#include <Servo.h>

#define SMov1 2
#define SMov2 5
#define SLuz A0
#define LED 13

Servo Puerta1;
Servo Puerta2;

void setup() {
  pinMode(SMov1, INPUT);
  pinMode(SMov2, INPUT);
  pinMode(SLuz, INPUT);
  pinMode(LED, OUTPUT);

  Puerta1.attach(3);
  Puerta2.attach(4);
  Serial.begin(9600);
}
//
void loop() {
  detectarLuz(SLuz, LED);
  int Entrada = digitalRead(SMov1);
  
  while(Entrada == 1){
    abrirPuertas();
  }
  int Salida = digitalRead(SMov2);
  while(Salida == 1){
  	cerrarPuertas();
  }
}

//

void detectarLuz(int dluz,int led) {
  int luz = analogRead( dluz );
  if(luz <= 50){
  	digitalWrite(led, HIGH); 
  }else{
  	digitalWrite(led, LOW);
  }
}
void abrirPuertas(){
  Puerta1.write(90);
  Puerta2.write(90);
  delay(1000);
}
void cerrarPuertas() {
  Puerta1.write(0);
  Puerta2.write(0);
  delay(1000);
}