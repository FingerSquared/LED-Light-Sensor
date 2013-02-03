/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define LED_N_SIDE 2
#define LED_P_SIDE 3
int led = 10;
int brightness = 10;
int fadeAmmount = 5;
int var;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
 pinMode(led, OUTPUT);
 Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  
  analogWrite(led, brightness);
  pinMode(LED_N_SIDE, OUTPUT);     
  pinMode(LED_P_SIDE, OUTPUT);
  digitalWrite(LED_N_SIDE, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_P_SIDE, LOW);   // turn the LED on (HIGH is the voltage level)
  
  pinMode(LED_N_SIDE,INPUT);
  digitalWrite(LED_N_SIDE,LOW);
  
  for(int j = 0; j < 32000; j++){
       
    
    if(digitalRead(LED_N_SIDE)==0){ 
    //digitalWrite(led, HIGH);
    var = j; 
    break;
    }
    if(digitalRead(LED_N_SIDE) == 1){
    //digitalWrite(led, LOW);
    }
  }
  
  digitalWrite(LED_P_SIDE, HIGH);
  digitalWrite(LED_N_SIDE, LOW);
  pinMode(LED_P_SIDE, OUTPUT);
  pinMode(LED_N_SIDE, OUTPUT);
  
 //if(var > 15000 && brightness < 50){
   if(var < 12000){
     brightness = 0;
   }else{
     brightness = map(var, 13000, 29000, 0, 20);
   }
    //brightness = brightness + 5;
 ///}
 // if(var < 15000 && brightness > 10){
 //   brightness = brightness -  5;
 //}
//Serial.println(var);
Serial.println(brightness);
  delayMicroseconds(5);
  
  
  /*delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, HIGH);
  delay(1000);*/
  
}

