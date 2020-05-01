#include <VirtualWire_Config.h>
#include <VirtualWire.h>
//Lado izquierdo
const int motor_1_1 = 10;
const int motor_1_2 = 11;
const int motor_2_1 = 12;
const int motor_2_2 = 13;
//Lado derecho
const int motor_3_1 = 4;
const int motor_3_2 = 5;
const int motor_4_1 = 6;
const int motor_4_2 = 7;

const int dataPin = 9;


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(motor_1_1, OUTPUT);
  pinMode(motor_1_2, OUTPUT);
  pinMode(motor_2_1, OUTPUT);
  pinMode(motor_2_2, OUTPUT);
  pinMode(motor_3_2, OUTPUT);
  pinMode(motor_3_2, OUTPUT);
  pinMode(motor_4_1, OUTPUT);
  pinMode(motor_4_2, OUTPUT);


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
    digitalWrite(motor_1_1, HIGH);
    digitalWrite(motor_1_2, LOW);
    digitalWrite(motor_2_1, LOW);
    digitalWrite(motor_2_2, HIGH);
  
    digitalWrite(motor_3_1, HIGH);
    digitalWrite(motor_3_2, LOW);
    digitalWrite(motor_4_1, LOW);
    digitalWrite(motor_4_2, HIGH);
  }
 void brake(){
   Serial.print("brake");
   digitalWrite(motor_1_1, LOW);
    digitalWrite(motor_1_2, LOW);
    digitalWrite(motor_2_1, LOW);
    digitalWrite(motor_2_2, LOW);
  
    digitalWrite(motor_3_1, LOW);
    digitalWrite(motor_3_2, LOW);
    digitalWrite(motor_4_1, LOW);
    digitalWrite(motor_4_2, LOW);
  }
  void turnRight(){
   Serial.print("turn right");
   digitalWrite(motor_1_1, HIGH);
    digitalWrite(motor_1_2, LOW);
    digitalWrite(motor_2_1, LOW);
    digitalWrite(motor_2_2, HIGH);

    digitalWrite(motor_3_1, LOW);
    digitalWrite(motor_3_2, LOW);
    digitalWrite(motor_4_1, LOW);
    digitalWrite(motor_4_2, LOW);
   delay(400);
   }
  void turnLeft(){
    Serial.print("turn left");
    digitalWrite(motor_3_1, HIGH);
    digitalWrite(motor_3_2, LOW);
    digitalWrite(motor_4_1, LOW);
    digitalWrite(motor_4_2, HIGH);

    digitalWrite(motor_1_1, LOW);
    digitalWrite(motor_1_2, LOW);
    digitalWrite(motor_2_1, LOW);
    digitalWrite(motor_2_2, LOW);
    
    delay(400);
    }
