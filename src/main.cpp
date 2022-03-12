#include <Arduino.h>


#define f 500
#define B 128
#define PinADC 34
#define Salida 26


int rADC = 0;
int Volts = 0;
int y = 0;
double j = 0;

void setup() {
analogReadResolution(8);
analogSetPinAttenuation(PinADC, ADC_0db);
}

void loop() {

     
 for(j=0; j<360; j+=0.00120){
  rADC = analogRead(PinADC);
  y = map(rADC, 0, 255, 50, 150);
  dacWrite(Salida, y*sin(2*PI*f*(j*PI/180)) + B);
  }

}