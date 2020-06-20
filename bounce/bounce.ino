#include<LiquidCrystal.h>

LiquidCrystal lcd(3,2,4,5,6,7);
const int button = 8;
char ascii = 0x00+0;
byte boy[8]={B01110,B10001,B10001,B01110,B00100,B11111,B00100,B11011};
byte life[8]={B00000,B00000,B11011,B11111,B01110,B00100,B00000,B00000};
byte block[8]={B11111,B11111,B11111,B11011,B11111,B11111,B11111,B11111};
byte ball[8]={B00000,B00000,B01110,B11111,B11111,B01110,B000000};

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  lcd.begin(16 ,2);  //Initialize 16x2 lcd
  lcd.clear();       //Clear lcd display screen
  lcd.createChar(1, boy);
  lcd.createChar(2, life);
  lcd.createChar(3, block);
  lcd.createChar(4, ball);

  test();
  driver();
}

void test(){
  for(int i=0; i<=15; i++) {
    lcd.setCursor(i,0);
    lcd.write(3);
  }
  delay(1000);
  lcd.setCursor(0,0);
  lcd.clear();
}

void driver(){
  int init_value = digitalRead(button);
  bool state = false;
  int chance = 13;
  for(int i=chance; i<=16; ++i){
    lcd.setCursor(i,0);
    lcd.write(2);
  }
  delay(500);

  if(init_value == 1){
    state = true;
    if(state){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.write(1);
    }
  }
  else if(init_value == 0){
    state = true;
    if(state){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.write(1);
    }
  }
  delay(100);
}

void loop(){ 
}
