
/*
  Brazoled - RETO 2 - Taller Arduino Basics I

  Ripolab Hacklab Noviembre 2017

  by @akirasan
  ripolab.org

*/


#include <Servo.h>

Servo servo_tilt, servo_pan;


void setup() {
  servo_tilt.attach(2); //servo superior
  //servo_tilt.writeMicroseconds(1500);

  servo_pan.attach(3); //servo inferior
  //servo_pan.writeMicroseconds(1500);

  servo_tilt.write(0);delay(1000);
  servo_tilt.write(90);delay(1000);
  servo_tilt.detach(); //servo superior
  servo_tilt.attach(2); //servo superior

  servo_pan.write(0);delay(1000);
  servo_pan.write(90);delay(1000);
  servo_pan.detach(); //servo inferior
  servo_pan.attach(3); //servo inferior

  analogWrite(5, 80);
  analogWrite(6, 80);
}


void lento(String servo, int angulo) {
  Servo servo_X;

  if (servo == "tilt") {
    servo_X = servo_tilt;
  }
  else
  {
    servo_X = servo_pan;
  }

  int estado = servo_X.read();

  Serial.print("ESTADO:"); Serial.println(estado);
  if (estado > angulo) {
    for (int i = estado; i > angulo; i--) {
      servo_X.write(i);
      delay(25);
    }
  }
  else {
    for (int i = estado; i <= angulo; i++) {
      servo_X.write(i);
      delay(25);
    }
  }
}





void ejes_lento(String servo1, int angulo1, String servo2, int angulo2) {
  Servo servo_X, servo_Y;

  if (servo1 == "tilt") {
    servo_X = servo_tilt;
  }
  else
  {
    servo_X = servo_pan;
  }


  if (servo2 == "tilt") {
    servo_Y = servo_tilt;
  }
  else
  {
    servo_Y = servo_pan;
  }

  int estado_X = servo_X.read();
  int estado_Y = servo_Y.read();

  while ((estado_X != angulo1) || (estado_Y != angulo2)) {
    if (estado_X < angulo1) {
      estado_X++;
    }
    else {
      if (estado_X > angulo1) {
        estado_X--;
      }
    }

    if (estado_Y < angulo2) {
      estado_Y++;
    }
    else {
      if (estado_Y > angulo2) {
        estado_Y--;
      }
    }
    servo_X.write(estado_X);
    servo_Y.write(estado_Y);
    delay(15);
  }
}



void loop() {


  lento("tilt",10);
  lento("pan",80);

  lento("tilt",80);
  lento("pan",10);

  //delay(1000);

}
