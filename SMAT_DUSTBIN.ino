#include<Servo.h>
#include"NewPing.h"

#define motor1 D2
#define mtotor2 D3
#define motor3 D4
#define motor4 D5
#define trig_1 D6
#define echo_1 D6
#define trig_2 D5
#define echo_2 D5
#define buzzer 4
#define MAx 400

Servo myservo;
NewPing sensor1(trig_1 ,echo_1 ,MAx);
NewPing sensor2(trig_2 ,echo_2 ,MAx);

float duration_1;
float distance_1;
float duration_2;
float distance_2;
int iterations = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(4);
  
}

void loop() {
  // put your main code here, to run repeatedly
  duration_1=sensor1.ping_median(iterations);

 delay(1000);

 duration_2=sensor2.ping_median(iterations);

 distance_1=(duration_1/2)*0.0343;
 distance_2=(duration_1/2)*0.0343;

//ultrasonic 


 
  Serial.print("Distance 1: ");
 
    if (distance_1 >= 400 || distance_1 <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.print(distance_1);
    Serial.print(" cm ");
    }

    if(distance_1<=12)
    {
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      digitalWrite(7,LOW);

      digitalWrite(4,HIGH);
      }
    
    Serial.print("Distance 2: ");
 
    if (distance_2 >= 400 || distance_2 <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.print(distance_2);
    Serial.print(" cm");
    }

    if(distance_2<=9)
    {
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(7,LOW);
      myservo.write(90);
      
      
      }
  
  Serial.println(" ");  
}
