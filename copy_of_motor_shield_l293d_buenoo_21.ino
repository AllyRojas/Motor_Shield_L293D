#include <Servo.h>

#define AVANCE    0B11100100
#define REVERSA   0B00011011
#define FRENO     0B00000000
#define DERECHA   0B01100011
#define IZQUIERDA 0B10011100

Servo servo_1;
Servo servo_2;

//Pin connected to ST_CP of 74HC595
const int ST_CP = 12;
//Pin connected to SH_CP of 74HC595
const int SH_CP = 4;
////Pin connected to DS of 74HC595
const int DS = 8;

void avanzar(){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, LSBFIRST, AVANCE);
  digitalWrite(ST_CP, HIGH);
  Serial.println("Avanza");
  delay(1000);
  }

void freno(){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, LSBFIRST, FRENO);
  digitalWrite(ST_CP, HIGH);
  Serial.println("Freno");
  delay(1000);
  }

void reversa(){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, LSBFIRST, REVERSA);
  digitalWrite(ST_CP, HIGH);
  Serial.println("Reversa");
  delay(1000);
  }

void derecha(){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, LSBFIRST, DERECHA);
  digitalWrite(ST_CP, HIGH);
  Serial.println("Derecha");
  delay(1000);
  } 

void izquierda(){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, LSBFIRST, IZQUIERDA);
  digitalWrite(ST_CP, HIGH);
  Serial.println("Izquierda");
  delay(1000);
  } 
  

void setup(){
  servo_1.attach(10);
  servo_2.attach(9);
  
  servo_1.write(10);
  servo_2.write(10);
  
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(DS, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  avanzar();
  freno();
  reversa();
  derecha();
  freno();
  izquierda();
  freno();
  
  // Servos
  
  servo_1.write(90);
  servo_2.write(180);
  delay(1000);
  
  servo_1.write(180);
  servo_2.write(90);
  delay(1000);
  
  servo_1.write(10);
  servo_2.write(10);
  delay(1000);
}