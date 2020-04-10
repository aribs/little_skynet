#include <VirtualWire_Config.h>
#include <VirtualWire.h>

//const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
//const int Echo = 3;   //Pin digital 3 para el Echo del sensor
//const int LedBlue = 4;
//const int LedYelow = 53;
const int rele1 = 6;
const int rele2 = 7;
const int dataPin = 9;


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  //pinMode(Trigger, OUTPUT); //pin como salida
 // pinMode(Echo, INPUT);  //pin como entrada
  //digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  //pinMode(LedBlue, OUTPUT);
  //pinMode(LedYelow, OUTPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  vw_setup(2000);
  vw_set_rx_pin(dataPin);
  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) 
  {
    Serial.print("Mensaje: ");
    Serial.print((char)buf[2]);
    if((char)buf[2] == '9'){
      foward();
      delay(100);
    }
    if((char)buf[2] == '3'){
      turnLeft();
      delay(100);
    }
    if((char)buf[2] == '1'){
      turnRight();
      delay(100);
    }
    if((char)buf[2] == '5'){
      brake();
      delay(100);
    }
     
  }
}

void foward() {
    Serial.print("go foward");
    //digitalWrite(LedBlue, HIGH);
    //digitalWrite(LedYelow, LOW); 
    digitalWrite(rele1, LOW);
    digitalWrite(rele2, LOW);
  }
 void brake(){
   Serial.print("brake");
   //digitalWrite(LedBlue, LOW);
   //digitalWrite(LedYelow, LOW); 
   digitalWrite(rele1, HIGH);
   digitalWrite(rele2, HIGH);
  }
  void turnRight(){
   Serial.print("turn right");
   //digitalWrite(LedYelow, HIGH);
   digitalWrite(rele2, LOW);
   digitalWrite(rele1, HIGH); 
   delay(400);
   }
  void turnLeft(){
    Serial.print("turn left");
    //digitalWrite(LedYelow, HIGH); 
    digitalWrite(rele2, HIGH);
    digitalWrite(rele1, LOW);
    delay(400);
    }
