#include<LiquidCrystal.h>

LiquidCrystal lcd(3,2,4,5,6,7);
const int button = 8;
char ascii = 0x00+0;
uint8_t boy[8]={B01110,B11011,B10001,B01110,B00100,B11111,B00100,B11011};
uint8_t life[8]={B00000,B00000,B11011,B11111,B01110,B00100,B00000,B00000};
uint8_t block[8]={B11111,B11111,B11111,B11011,B11111,B11111,B11111,B11111};
uint8_t ball[8]={B00000,B00000,B01110,B11111,B11111,B01110,B00000};

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

  //call test/debug code here
}

void driver(){
  int life = 3;
  long sec_pass = millis() / 1000;

  //life
  for(int i=13; i<=16; ++i){
    lcd.setCursor(i,0);
    lcd.write(2);

  }
  //boy
  while(life != 0){
    int init_value = digitalRead(button);
    if(init_value == 1){
      lcd.setCursor(1,1);
      lcd.write(" ");
      lcd.setCursor(1,0);
      lcd.write(1);
    }
    else{
      lcd.setCursor(1,0);
      lcd.write(" ");
      lcd.setCursor(1,1);
      lcd.write(1);
    }

    life -= 1;
    for(int i=13; i>=15; i++){
      lcd.setCursor(i, 0);
      lcd.write(" ");
    }
    //Main Game mechanics
  }
  delay(100);
}

void loop(){
  driver();
}
