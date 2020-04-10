#include <VirtualWire_Config.h>
#include <VirtualWire.h>

const int dataPin = 2;
const int joystickX = A2;
const int joystickY = A1;

void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
    vw_set_tx_pin(dataPin);
}

void loop()
{
    int xposition = analogRead(joystickX);
    int yposition = analogRead(joystickY);
    int posSend = returnDirection(xposition, yposition);
    char buf[VW_MAX_MESSAGE_LEN];
    String str;
    str = String(posSend);
    str.toCharArray(buf,sizeof(buf)); // Convertir a char array
    Serial.print(buf);
    Serial.print("\n");
    vw_send((uint8_t *)buf, 3); // Enviar array, envía un código de 3 cifras correspondiente al char: Flecha arriba, 479, flecha izquierda, 483, flecha derecha 481, flecha abajo o parado, 485
    vw_wait_tx(); // Esperar envio
    delay(200);
}
 char* returnDirection(int xposition, int yposition){
    //return top direction
    if(yposition < 480){ 
      return "1";
    }
    else if(xposition < 480){
       return "4"; 
     }
    else if(xposition > 550) {
      return "2"; 
     }
    else {
      return "3"; 
     }
  }
