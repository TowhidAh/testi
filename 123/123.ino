
// for test git
#include <LiquidCrystal.h>
const int LCD_Pin_RS = 7;

const int LCD_Pin_E = 9;
const int LCD_Pin_D4 = 10;
const int LCD_Pin_D5 = 11;
const int LCD_Pin_D6 = 12;
const int LCD_Pin_D7 = 13;


LiquidCrystal lcd(LCD_Pin_RS, LCD_Pin_E, LCD_Pin_D4, LCD_Pin_D5, LCD_Pin_D6, LCD_Pin_D7);






void setup() {
    ;
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("towhid");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("lsalammmmmmmm");
  delay(500);
  
 

}
