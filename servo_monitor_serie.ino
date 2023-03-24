/*
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h>
 * e a entrada serie para o posicionamento
 * do mesmo.
 */

#include <Servo.h>

//Pin de control do servo
#define CTRL 3

//Pin de lectura do potenc
#define POT A5

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int angulo = 0;
int veloc = 3000;

String orde ="";

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop() {
  //Comprobamos se hai orde no teclado
  if(Serial.available()) {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase(); 
    if(orde.equals("esquerda")){angulo = 180;}
    else if(orde.equals("Diagonalesquerda")){angulo = 135;}
    else if(orde.equals("centro")){angulo = 90;}
    else if(orde.equals("Diagonaldereita")){angulo = 45;}
    else if(orde.equals("dereita")){angulo = 0;}
  
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) angulo = tmp;
      else angulo = 0;
    }
  } 
  else {
    
    //Lectura do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  }

  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
  Serial.println(angulo);
  
}
  


