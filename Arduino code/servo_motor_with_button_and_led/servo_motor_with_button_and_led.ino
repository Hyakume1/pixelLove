#include <Servo.h>
#include <SR04.h>

Servo myservo; //creating servo object

//this is for the sr04 sensor, so that i can swipe the air
#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN); //making the object with the parameters


int srvpin = 9; //servo pin

//button pin
int btnPin = 7;

//pins for led
#define red 3
#define green 4
#define blue 5

void setup() {
  // put your setup code here, to run once:
  myservo.attach(srvpin); //using pin 9 for the servo
  myservo.write(0); //sets the servo at 0 position
  
  pinMode(btnPin, INPUT_PULLUP); // for the button

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  digitalWrite(green, HIGH); //set it to green so that the user 
  //know that they can move the servo

}

void loop() {
  // put your main code here, to run repeatedly:
/*
  //this is for the button
  if(digitalRead(btnPin) == LOW && myservo.read()==0){  
    
    digitalWrite(green, LOW);
    analogWrite(red, 255);
    delay(200);// this is so that it has time to turn red until the servo moves
    
    myservo.write(180);
    delay(400);
    
    analogWrite(red, 0);
    digitalWrite(green, HIGH);
    delay(500);
  }//end of if
  
  if(digitalRead(btnPin) == LOW && myservo.read()==180){  

    digitalWrite(green, LOW);
    analogWrite(red, 255);
    delay(200);
    
    myservo.write(0);
    delay(400);

    analogWrite(red, 0);
    digitalWrite(green, HIGH);
    delay(500);
  }//end of if
*/
  //this is for the proximity sensor
  if(sr04.Distance() < 30 && myservo.read()==0){  
    
    digitalWrite(green, LOW);
    analogWrite(red, 255);
    delay(200);// this is so that it has time to turn red until the servo moves
    
    myservo.write(180);
    delay(400);
    
    analogWrite(red, 0);
    digitalWrite(green, HIGH);
    delay(500);
  }//end of if
  
  if(sr04.Distance() < 50 && myservo.read()==180){  

    digitalWrite(green, LOW);
    analogWrite(red, 255);
    delay(200);
    
    myservo.write(0);
    delay(400);

    analogWrite(red, 0);
    digitalWrite(green, HIGH);
    delay(500);
  }//end of if
}//end of loop
