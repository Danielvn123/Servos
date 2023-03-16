/*
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h> e 
 * ligado a un potenciómetro.
 
 Autor: Daniel Vilas
Data: Febreiro de 2023

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
int veloc = 125;  //1000 dividido entre 8 = 125

void setup() {
  motor.attach(CTRL);
}

void loop() {
  //Lectura do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
}
