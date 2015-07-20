// definição das entradas do arduino (saida do bitalino)
const int o1 = 8;
const int o2 = 7;
const int o3 = 12;
const int o4 = 13;

// definição dos estados de entrada
int o1state, o2state, o3state, o4state;

// definição das saidas (led)
int ledb = 9;           // the pin that the LED is attached to
int ledg = 10;           // the pin that the LED is attached to
int ledr = 11;
int led2b = 6;           // the pin that the LED is attached to
int led2g = 5;           // the pin that the LED is attached to
int led2r = 3;

// definição do número do caso do HR
int n = 0;

// definição dos parametros do led
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   // inputs
   pinMode(o1, INPUT);
   pinMode(o2, INPUT);
   pinMode(o3, INPUT);
   pinMode(o4, INPUT);
   
   //outputs
   pinMode(ledb, OUTPUT); //AZUL
   pinMode(ledg, OUTPUT); //VERDE
   pinMode(ledr, OUTPUT); //VERMELHO
   pinMode(led2b, OUTPUT); //AZUL
   pinMode(led2g, OUTPUT); //VERDE
   pinMode(led2r, OUTPUT); //VERMELHO

}

void loop() {
  
  // leitura dos estados de entrada
  o1state = digitalRead(o1);
  o2state = digitalRead(o2);
  o3state = digitalRead(o3);
  o4state = digitalRead(o4);

  
  // definição do estado do caso consoante a entrada 
  n = (o1state*(pow(2,3))) + (o2state*(pow(2,2))) + (o3state*(pow(2,1))) + (o4state*(pow(2,0)));

  //cases
  if (n == 0){
    //azul
        analogWrite(ledb, 255);
        analogWrite(led2b, 255);
        analogWrite(ledg, LOW);
        analogWrite(led2g, LOW);
        analogWrite(ledr, LOW);
        analogWrite(led2r, LOW);  
    }
    
    if (n == 1){
    //azul
        analogWrite(ledb, brightness);    
        analogWrite(led2b, brightness);
        analogWrite(ledg, LOW);
        analogWrite(led2g, LOW);
        analogWrite(ledr, LOW);
        analogWrite(led2r, LOW); 
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }        
        delay(100);
    }

    if (n == 2){  
        //azul e 25% verde
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness/4);
        analogWrite(ledr, LOW);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness/4);
        analogWrite(led2r, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(90);
    }
      
    if (n == 3){
        //azul e 50 % verde
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness/2);
        analogWrite(ledr, LOW);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness/2);
        analogWrite(led2r, LOW);
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        
        delay(80);
    
    }      
    if (n == 4){
    //azul e verde
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness);
        analogWrite(ledr, LOW);        
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness);
        analogWrite(led2r, LOW);
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        
        delay(75);
    
    }      
    
    if (n == 5){
    //branco
        
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness);
        analogWrite(ledr, brightness);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness);
        analogWrite(led2r, brightness);
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(70);
        
    }
    
    if (n == 6){
    //branco
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness);
        analogWrite(ledr, brightness);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness);
        analogWrite(led2r, brightness);
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(65);
        
    }


    if (n == 7){
    //branco
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness);
        analogWrite(ledr, brightness);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness);
        analogWrite(led2r, brightness);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(60);        
    }
    
    if (n == 8){
    //branco
        analogWrite(ledb, brightness);
        analogWrite(ledg, brightness);
        analogWrite(ledr, brightness);
        analogWrite(led2b, brightness);
        analogWrite(led2g, brightness);
        analogWrite(led2r, brightness);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(55);        
    }

    if (n == 9){
    //branco e 25% azul
        analogWrite(ledb, brightness/2);
        analogWrite(ledg, brightness);
        analogWrite(ledr, brightness);
        analogWrite(led2b, brightness/2);
        analogWrite(led2g, brightness);
        analogWrite(led2r, brightness);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(50);        
    }
    
    if (n == 10){
    //azul e vermelho
        analogWrite(ledb, brightness);
        analogWrite(ledr, brightness);
        analogWrite(ledg, LOW);
        analogWrite(led2b, brightness);
        analogWrite(led2r, brightness);
        analogWrite(led2g, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(45);        
    }     
    
    if (n == 11){
    //50% azul e vermelho
        analogWrite(ledb, brightness/2);
        analogWrite(ledr, brightness);
        analogWrite(ledg, LOW);
        analogWrite(led2b, brightness/2);
        analogWrite(led2r, brightness);
        analogWrite(led2g, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(35);        
        
    }
     
    if (n == 12){
        //25% azul e vermelho
        analogWrite(ledr, brightness);  
        analogWrite(ledb, brightness/4);
        analogWrite(ledg, LOW);
        analogWrite(led2r, brightness);  
        analogWrite(led2b, brightness/4);
        analogWrite(led2g, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        
        delay(25);        
        
    }
     
    if (n == 13){
        //12.5% azul e vermelho
        analogWrite(ledr, brightness); 
        analogWrite(ledb, brightness/8);
        analogWrite(ledg, LOW);
        analogWrite(led2r, brightness); 
        analogWrite(led2b, brightness/8);
        analogWrite(led2g, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(15);        
        
    }

    if (n == 14){
        //vermelho
        analogWrite(ledr, brightness); 
        analogWrite(ledb, LOW);
        analogWrite(ledg, LOW);
        analogWrite(led2r, brightness); 
        analogWrite(led2b, LOW);
        analogWrite(led2g, LOW);
        
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ;
        }
        delay(5);        
        
    }
     
    if (n == 15){ 
        //vermelho
        analogWrite(ledr, 255); 
        analogWrite(ledb, LOW);
        analogWrite(ledg, LOW);
        analogWrite(led2r, 255); 
        analogWrite(led2b, LOW);
        analogWrite(led2g, LOW);
         
        
    }
}
