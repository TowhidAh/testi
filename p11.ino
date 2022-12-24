#include <LiquidCrystal.h>
const int motor  =6 ;
//const int sensor = 5;
int sensor_an = A0;
int thresholdValue = 500;
int print_lcd = 0 ;
//*********************************************Config Pin_LCD
const int LCD_Pin_RS = 7;

const int LCD_Pin_E = 9;
const int LCD_Pin_D4 = 10;
const int LCD_Pin_D5 = 11;
const int LCD_Pin_D6 = 12;
const int LCD_Pin_D7 = 13; 
LiquidCrystal lcd(LCD_Pin_RS,  LCD_Pin_E, LCD_Pin_D4, LCD_Pin_D5, LCD_Pin_D6, LCD_Pin_D7);


void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  pinMode (sensor_an  ,INPUT_PULLUP);
 
  

  lcd.begin(16, 2);
 
  lcd.clear();
}
 


//void loop() {
//  
//   
//  
//  
//
//  
// 
//    if(digitalRead(sensor)==1)
//    {
//  
//  
//      
//   
//       digitalWrite ( motor , HIGH );
//       delay(1000);
//       
//    }
//    else{
// 
//  
//     
//  
//      digitalWrite( motor ,LOW);
//      delay(1000);
//    }
//}
void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(sensor_an);
Serial.println(sensorValue);
delay(500);
if(sensorValue < thresholdValue){
//Serial.println(" - Doesn't need watering");
//
//lcd.setCursor(0,0);
//lcd.print("Automatic Mode    ");

digitalWrite ( motor , LOW );

}
else {
//Serial.println(" - Time to water your plant");
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("Automatic Mode    ");
digitalWrite ( motor , HIGH );
}
delay(500);
}
      
     
