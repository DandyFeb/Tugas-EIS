#include <LiquidCrystal_I2C.h>

#define pirpin 12

int statuspir = LOW;
int motion;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(pirpin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Gerakan");
  lcd.setCursor(0,0);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  motion = digitalRead(pirpin);
  if (motion == HIGH)
  {
    lcd.setCursor(0,0);
    lcd.print("Ada      ");
    statuspir = HIGH;
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Tidak Ada");
    statuspir = LOW;
  }
  delay(250);
}
