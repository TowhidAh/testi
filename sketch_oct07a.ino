#include <TimerOne.h>
#include <LiquidCrystal.h>


//*********************************************Config Pin_Keypad
const int PIN_SW_DOWN = 3;
const int PIN_SW_SET = 5;
const int PIN_SW_UP = 4;
const int motor = 6 ;
const int PIN_on_off = 2 ;
//*********************************************Setup LCD

//*********************************************Config Pin_LCD

const int LCD_Pin_RS = 7;

const int LCD_Pin_E = 9;
const int LCD_Pin_D4 = 10;
const int LCD_Pin_D5 = 11;
const int LCD_Pin_D6 = 12;
const int LCD_Pin_D7 = 13;


LiquidCrystal lcd(LCD_Pin_RS,  LCD_Pin_E, LCD_Pin_D4, LCD_Pin_D5, LCD_Pin_D6, LCD_Pin_D7);
//*********************************************Config Value

boolean key  = 0;
int _hour, _minute ,_day;


boolean key_SET , key_DOWN, key_UP , on_off  ;
int now_hour;
int now_minute;
int now_day ;
int now_second ;
long timeing;
int now_timeing;
long watering_now ;

int mi ;
int hu ;
int da ;
int i ;
int j;
int T ;
int f =100000 ;

//*********************************************setup stoping
long int starting  ;
//********************************************* setup Watering time
long int watering ;
long stop_time  ;
void setup() {
  
  pinMode(PIN_SW_DOWN, INPUT_PULLUP);
  pinMode(PIN_SW_SET, INPUT_PULLUP);
  pinMode(PIN_SW_UP, INPUT_PULLUP);
  pinMode(PIN_on_off, INPUT_PULLUP);
  pinMode (motor , OUTPUT) ;
 

 
 lcd.begin(16, 2);
 lcd.clear();


}

//*********************************************Subprogram loop()
void loop() {
  lcd.setCursor (0 , 0) ;
  lcd.print("set timeing...");
  lcd.setCursor(0, 1);
  lcd.print("D");
  lcd.print(":");
  lcd.print(now_day);
  lcd.print("/");
  lcd.print("H");
  lcd.print(":");
  lcd.print(now_hour);
  lcd.print("/");
  lcd.print("M");
  lcd.print(":");
  lcd.print(now_minute);
  lcd.print("/");
  lcd.print("W");
  lcd.print(":");
  lcd.print(now_timeing);
 
 
  
  key_UP = digitalRead(PIN_SW_UP);
  key_SET = digitalRead(PIN_SW_SET);
  key_DOWN = digitalRead(PIN_SW_DOWN);
  on_off  = digitalRead(PIN_on_off );
  if (key == 0 && key_SET == 0 && key_DOWN == 1 && key_UP == 1 && on_off == 1    ) {
    key = 1;
    _hour = now_hour;
    _minute = now_minute;
    _day = now_day;
    timeing = now_timeing;
    watering= watering_now  ;
    SET_minute();
    
    
  
  }
  if (key == 1 && key_SET == 1 && key_DOWN == 1 && key_UP == 1 && on_off== 1 ) {
    key = 0;
     
 
  }
  
  


}
//*********************************************Subprogram SET_hour()
void SET_hour() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> SET Hour");
  lcd.setCursor (0, 1);
  lcd.print("Hour = ");
  while (1) {
    lcd.setCursor (7, 1);
    lcd.print(_hour);
    lcd.print("   ");
    key_UP = digitalRead(PIN_SW_UP);
    key_SET = digitalRead(PIN_SW_SET);
    key_DOWN = digitalRead(PIN_SW_DOWN);
    if (key == 0 && key_SET == 1 && key_DOWN == 0 && key_UP == 1 && on_off == 1) {
      key = 1;
      if (_hour == 0) {
        _hour = 23;
      } else {
        _hour--;
      }
    }
    if (key == 0 && key_SET == 1 && key_DOWN == 1 && key_UP == 0 && on_off == 1) {
      key = 1;
      if (_hour == 23) {
        _hour = 0;
      } else {
        _hour++;
      }
    }
    if (key == 0 && key_SET == 0 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 1;
      break;
    }
    if (key == 1 && key_SET == 1 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 0;
    }
  }
 
  SET_day();
  now_hour=_hour  ;
}
//*********************************************Subprogram SET_minute()
void SET_minute() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> SET Minute");
  lcd.setCursor (0, 1);
  lcd.print("Minute = ");
  while (1) {
    lcd.setCursor (9, 1);
    lcd.print(_minute);
    lcd.print("   ");
    key_UP = digitalRead(PIN_SW_UP);
    key_SET = digitalRead(PIN_SW_SET);
    key_DOWN = digitalRead(PIN_SW_DOWN);
    if (key == 0 && key_SET == 1 && key_DOWN == 0 && key_UP == 1 && on_off == 1) {
      key = 1;
      if (_minute == 0) {
        _minute = 59;
      } else {
        _minute--;
      }
    }
    if (key == 0 && key_SET == 1 && key_DOWN == 1 && key_UP == 0 && on_off == 1) {
      key = 1;
      if (_minute == 59) {
        _minute = 0;
      } else {
        _minute++;
      }
    }
    if (key == 0 && key_SET == 0 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 1;
      break;
    }
    if (key == 1 && key_SET == 1 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 0;
    }
  }

  now_minute=_minute ;
  SET_hour();
 
}


//*********************************************Subprogram SET_day()
void SET_day() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> SET Day");
  lcd.setCursor (0, 1);
  lcd.print("Day = ");
  while (1) {
    lcd.setCursor (6, 1);
    lcd.print(_day);
    lcd.print("   ");
    key_UP = digitalRead(PIN_SW_UP);
    key_SET = digitalRead(PIN_SW_SET);
    key_DOWN = digitalRead(PIN_SW_DOWN);
    if (key == 0 && key_SET == 1 && key_DOWN == 0 && key_UP == 1 && on_off == 1) {
      key = 1;
      if (_day == 1) {
        _day = 31;
      } else {
        _day--;
      }
    }
    if (key == 0 && key_SET == 1 && key_DOWN == 1 && key_UP == 0 && on_off == 1) {
      key = 1;
      if (_day == 31) {
        _day = 1;
      } else {
        _day++;
      }
    }
    if (key == 0 && key_SET == 0 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 1;
      break;
    }
    if (key == 1 && key_SET == 1 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 0;
     
      
    }
  }
 
  now_day = _day ;
 Watering_time();
}
//****************************************************
void Watering_time() {
  lcd.clear();
  
  

  lcd.setCursor(0, 0);
  lcd.print("> SET timeing");
  lcd.setCursor (0, 1);
  lcd.print("timeing = ");
  while (1) {
    lcd.setCursor (9, 1);
    lcd.print(timeing);
    lcd.print("   ");
    key_UP = digitalRead(PIN_SW_UP);
    key_SET = digitalRead(PIN_SW_SET);
    key_DOWN = digitalRead(PIN_SW_DOWN);
    if (key == 0 && key_SET == 1 && key_DOWN == 0 && key_UP == 1 && on_off == 1) {
      key = 1;
      if (timeing == 0) {
        timeing = 59;
      } else {
        timeing--;
      }
    }
    if (key == 0 && key_SET == 1 && key_DOWN == 1 && key_UP == 0 && on_off == 1) {
      key = 1;
      if (timeing == 59) {
        timeing = 0;
      } else {
        timeing++;
      }
    }
    if (key == 0 && key_SET == 0 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 1;
      break;
    }
    if (key == 1 && key_SET == 1 && key_DOWN == 1 && key_UP == 1 && on_off == 1) {
      key = 0;
     
    }
  }

    
  now_timeing=timeing ;
  run_motor();
 
}
//****************************************************
void run_motor(){
mi = now_minute *6;
hu = now_hour* 3600;
da = now_day* 86400 ;
starting = da + hu + mi ;
watering = now_timeing*6 ;
stop_time = starting + watering ;
j = starting ; 


 

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> runing");
  lcd.setCursor (0, 1);
  lcd.print("time = ");
  while (1) {
    lcd.setCursor (7, 1);
    lcd.print(T);
    lcd.setCursor (11 , 1 );
    lcd.print ("s");
    lcd.print("   ");
    key_SET = digitalRead(PIN_SW_SET);
    on_off  = digitalRead(PIN_on_off );
   
    
    if (key == 0 && key_SET == 1 && on_off == 0) {
 
  key = 1 ;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Run);
  
      
    }
    if (key == 0 && key_SET == 0 && on_off ==1 && key_DOWN == 1 && key_UP == 1 ) {
      key = 1;
      break;
    }
    if (key == 1 && key_SET == 1 && on_off == 1 && key_DOWN == 1 && key_UP == 1 ) {
      key = 0;
      
    }
  }
  
   watering = watering_now ;
 
   
  

}
void Run (){

  
  
  i++;
  
  
  T = j - i ;
   if (i == starting){
    j = watering + i ;
    
    digitalWrite(motor,HIGH);
  }
    
    if ( i == stop_time ) {
      i = 0;
      j= starting;
      digitalWrite(motor,LOW);
      
      }
  
   


    
  
  
}

  
