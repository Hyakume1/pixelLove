#include <LiquidCrystal.h>
#include "SR04.h"

//creating lcd object
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//creating proximity sensor object and assigning pins
#define echo 13
#define trig 12
SR04 sens = SR04(echo, trig);
float dist; //distance

void setup() {
  
  //lcd with 16 columns and 2 rows
  lcd.begin(16,2);

  //top line
  lcd.setCursor(0, 0);
  lcd.print("current distance:");

  //cm fixed in screen
  lcd.setCursor(5, 1);
  lcd.print("cm");

  //meters fixed on screen
  lcd.setCursor(15, 1);
  lcd.print("M");

}//end of setup

void loop() {
  //register the distance
  
  dist = sens.Distance();
   
  //show distance 
  cmResult(dist);
  mResult(dist);
  delay(500);
  

}// end of main loop

void mResult(float dist){
  lcd.setCursor(10, 1);
  
  if(dist >99999)
  lcd.print("ERROR");
  
  else
  dist /= 100.0;
  do{
     if(dist <= 9){
      lcd.setCursor(9,1);
      lcd.print("  ");
      break;
    }
    
    if(dist <= 99){
      lcd.setCursor(9,1);
      lcd.print(" ");
      break;
    }
    
  }while(true);
  
  lcd.print(dist,1);
  
}//end of meter converter

//this shows the results in cm
void cmResult(int dist){
  lcd.setCursor(0, 1);
  
  do {
    if (dist<=9){
      lcd.setCursor(0, 1);
      lcd.print("   ");
      break;
    }
    
    if (dist<=99){
      lcd.setCursor(0, 1);
      lcd.print("  ");
      break;
    }
    
    if (dist<=999){
      lcd.setCursor(0, 1);
      lcd.print(" ");
      break;
    }
    
    if (dist<=9999){
      lcd.setCursor(0, 1);
      lcd.print("");
      break;
    }
    
  } while(true); //end of while
  lcd.print(dist);
  
}//end of cmResult
