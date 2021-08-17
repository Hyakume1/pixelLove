/*This program allows you to now only regulate the speed, but so that the fan automatically starts if it senses an object near it
*/

#include "SR04.h"

//pins for the ultrasonic sensor
//remember that it can't have a common ground
#define trigPin 9
#define echoPin 8

//pins for dc motor
#define speedPin 3
#define dirPin1 4
#define dirPin2 5

//objects
SR04 sens = SR04(echoPin, trigPin);

//variables
const double oneUnit = 3.945;
int motorSpeed;
int potentiometer;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  Serial.begin(9600);
    // making the fan go clockwise
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
}

void loop() {
  
  distance = sens.Distance();
  
  if(distance >= 60)
  analogWrite(speedPin, 0);
  
  if(distance < 150){
//read current potentiometer value
//for every 3.945, it's 1 value of analog read until 255.
 potentiometer = analogRead(A0);
 motorSpeed = potentiometer/oneUnit;
 
 if(motorSpeed < 60)
 motorSpeed = 0;
 else if(motorSpeed >250)
 motorSpeed = 255;
 
 Serial.print(distance);
 Serial.print(" ");
 Serial.println(motorSpeed);
 delay(100);
 analogWrite(speedPin, motorSpeed);
 delay(100);
  }
 
  
 




  
/* this shows how to change the speed and rotation
  do{
    motorSpeed += 1;
    analogWrite(speedPin, motorSpeed);

    //write it in the serial monitor
    analogRead(motorSpeed);
    Serial.println(motorSpeed);
    
    delay(100);
  }while(motorSpeed < 255);

  delay(1000);
  
  do{
    motorSpeed -= 1;
    analogWrite(speedPin, motorSpeed);

    //write it in the serial monitor
    analogRead(motorSpeed);
    Serial.println(motorSpeed);
    
    delay(100);
  }while(motorSpeed > 0);
  
  delay(1000);
  
//OTHER DIRECTION
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);

  do{
    motorSpeed += 1;
    analogWrite(speedPin, motorSpeed);

    //write it in the serial monitor
    analogRead(motorSpeed);
    Serial.println(motorSpeed);
    
    delay(100);
  }while(motorSpeed < 255);

  delay(1000);
  
  do{
    motorSpeed -= 1;
    analogWrite(speedPin, motorSpeed);

    //write it in the serial monitor
    analogRead(motorSpeed);
    Serial.println(motorSpeed);
    
    delay(100);
  }while(motorSpeed > 0);

  delay(1000);
  */
}
