# -*- coding: cp1252 -*-

from pygame import mixer
import bitalino
import matplotlib.pyplot as plt
import numpy as np
from scipy import signal as sig
import math
import thread
import time

#Filtro Lowpass
# Tirado de:
#http://dsp.stackexchange.com/questions/2864/how-to-write-lowpass-filter-for-sampled-signal-in-python
def firlowpass(interval, freq, sampling_rate):
    nfreq = freq/(0.5*sampling_rate)
##    taps =  sampling_rate + 1
    a = 1
    b = sig.firwin(sampling_rate, cutoff=nfreq)
    firstpass = sig.lfilter(b, a, interval)
    secondpass = sig.lfilter(b, a, firstpass[::-1])[::-1]
    return secondpass

#Definição casos HR
def switchHR(HR):
    if HR < 40:
        saida = [0, 0 ,0 ,0]
        n = 0
    elif HR >= 40 and HR < 50:
        saida = [0, 0 ,0 ,1]
        n = 1
    elif HR >= 50 and HR < 60:
        saida = [0, 0 ,1 ,0]
        n = 1
    elif HR >= 60 and HR < 65:
        saida = [0, 0 ,1 ,1]
        n = 1
    elif HR >= 65 and HR < 70:
        saida = [0, 1 ,0 ,0]
        n = 1
    elif HR >= 70 and HR < 75:
        saida = [0, 1 ,0 ,1]
        n = 2
    elif HR >= 75 and HR < 80:
        saida = [0, 1 ,1 ,0]
        n = 2
    elif HR >= 80 and HR < 85:
        saida = [0, 1 ,1 ,1]
        n = 2
    elif HR >= 85 and HR < 90:
        saida = [1, 0 ,0 ,0]
        n = 2
    elif HR >= 90 and HR < 95:
        saida = [1, 0 ,0 ,1]
        n = 3
    elif HR >= 95 and HR < 100:
        saida = [1, 0 ,1 ,0]
        n = 3
    elif HR >= 100 and HR < 110:
        saida = [1, 0 ,1 ,1]
        n = 3
    elif HR >= 110 and HR < 120:
        saida = [1, 1 ,0 ,0]
        n = 3
    elif HR >= 120 and HR < 130:
        saida = [1, 1 ,0 ,1]
        n = 3
    elif HR >= 130 and HR < 140:
        saida = [1, 1 ,1 ,0]
        n = 3
    else:
        saida = [1, 1 ,1 ,1]
        n = 4

    return saida, n

def musica(n, n_ant):
    
    global mixer
    if mixer.music.get_busy() == False:
        mixer.init()
        if n == 1:
            mixer.music.load('LOW.mp3')
            mixer.music.play()
        elif n == 2: 
            mixer.music.load('NORMAL.mp3')
            mixer.music.play()
        elif n == 3:   
            mixer.music.load('HIGH.mp3')
            mixer.music.play()
        elif n==0: 
            mixer.music.load('flatline.mp3')
            mixer.music.play()
        else:
            mixer.music.load('fast.mp3')
            mixer.music.play()  
        
    elif n_ant != n and n_ant != -1:
        mixer.music.stop()
        mixer.init()
        if n == 1:
            mixer.music.load('LOW.mp3')
            mixer.music.play()
        elif n == 2: 
            mixer.music.load('NORMAL.mp3')
            mixer.music.play()
        elif n==3: 
            mixer.music.load('HIGH.mp3')
            mixer.music.play()  
        elif n==0: 
            mixer.music.load('flatline.mp3')
            mixer.music.play()
        else:
            mixer.music.load('fast.mp3')
            mixer.music.play()            
            
print 'CARDIMAX - Robótica Médica \nAna Rita Lopes | Inês Cruz | Joana Dias\n'

# BITalino iniciação
mac = '98:D3:31:B2:13:94'
samp_rate = 100 #Hz
seconds_aqc = 10 #seconds of aquisition
nSamples = seconds_aqc*samp_rate
analogChannels = [0]

bit = bitalino.BITalino(mac)

version = bit.version()
print bit.version()
print 'Starting acquisition...\nCTRL+C to stop.\n'

bit.start(samp_rate,analogChannels)

x = np.linspace(0,seconds_aqc,nSamples)
cutOff = 3 #cutoff frequency in Hz

loop_var = 1
n_ant = -1
global mixer
mixer.init()
try:
    while loop_var:
        #Início aquisição de seconds_aqc (s)
        data = bit.read(nSamples)
        bvp = data[:,5]

        #======Processamento de sinal======#
        #Detrending
        bvpdet = sig.detrend(bvp)
        bvpfilt = firlowpass(bvpdet,cutOff,samp_rate)
        
        # Contagem de batimentos em seconds_aqc
        thres = max(bvpfilt)/3
        c=0
        i=0
        index=[]
##        print max(bvpfilt)
        while i < nSamples:
            if bvpfilt[i] >= thres and bvpfilt[i-1]-bvpfilt[i] > 0 and max(bvpfilt)>20:
                c+=1
                index.append(i)
                i+=14
            i+=1

        HR = c*60/seconds_aqc #bpm
        print str(HR)+' beat per minute.\n'
        #Envio de HR em binário para portas digitais
        (saida,n) = switchHR(HR)

        bit.trigger(saida)
        print 'Trigger: '+str(saida)+'\nState: '+str(n)+'\n'

        #Thread for music
        thread.start_new_thread(musica,(n,n_ant))

        #Save current state
        if n == 1:
            n_ant = n
        elif n == 2:
            n_ant = n
        else:
            n_ant = n

##        time.sleep(0.5)
except:
    KeyboardInterrupt
    print 'Acquisition stopped'

mixer.music.stop()
bit.stop()
bit.close()
thread.exit()



