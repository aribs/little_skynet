const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
const int LedBlue = 4;
const int LedYelow = 53;
const int rele1 = 6;
const int rele2 = 7;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(LedBlue, OUTPUT);
  pinMode(LedYelow, OUTPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  
}

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);

  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //EnviaImos serialmente el valor de la distancia

  if(d > 60 ){
    foward();
   }
  else{
    brake();
    int rnd = random(1,2);
    if(rnd <= 1){
      turnRight(); 
     }
     else{
      turnLeft();
      }
   }
  delay(100);         //Hacemos una pausa de 100ms
}

void foward() {
    digitalWrite(LedBlue, HIGH);
    digitalWrite(LedYelow, LOW); 
    digitalWrite(rele1, LOW);
    digitalWrite(rele2, LOW);
  }
 void brake(){
   digitalWrite(LedBlue, LOW);
   digitalWrite(LedYelow, LOW); 
   digitalWrite(rele1, HIGH);
   digitalWrite(rele2, HIGH);
  }
  void turnRight(){
   digitalWrite(LedYelow, HIGH);
   digitalWrite(rele2, LOW);
   digitalWrite(rele1, HIGH); 
   delay(400);
   }
  void turnLeft(){
    digitalWrite(LedYelow, HIGH); 
    digitalWrite(rele2, HIGH);
    digitalWrite(rele1, LOW);
    delay(400);
    }
