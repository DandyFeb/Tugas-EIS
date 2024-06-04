#include <LiquidCrystal_I2C.h>
#define BUZZER_PIN 2
#define LED_PIN 3
#define SENSOR A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

int gas_value;
int gas_min = 300;
int gas_max = 2000;

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  gas_value = analogRead(SENSOR);

  lcd.print("Gas Value: ");
  lcd.println(gas_value);
  lcd.setCursor(0,1);

  if (gas_value >= gas_min && gas_value <= gas_max)
  {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    lcd.print("Safe");
  }
  else
  {
    tone(BUZZER_PIN, 1000);
    digitalWrite(LED_PIN, HIGH);
    lcd.print("DANGER!!!");
  }
  delay(500);
}
