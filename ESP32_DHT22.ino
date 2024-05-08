#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

#define DHTPIN 19
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define SERVO_PIN 15
Servo servo;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  servo.attach(SERVO_PIN);
  servo.write(90);
}

int pos = 0;
float hum;
float temp;

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Temperatur: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Status: ");
  if (temp > 40)
    lcd.print("Panas ");
  else if (temp < 20)
    lcd.print("Dingin");
  else
    lcd.print("Normal");

  lcd.setCursor(0,2);
  lcd.print("Kelembapan: ");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0,3);
  lcd.print("Status: ");
  if (hum > 50)
    lcd.print("Basah ");
  else if (hum < 30)
    lcd.print("Kering");
  else
    lcd.print("Normal");

  if (temp > 40 || hum > 50)
  {
    servo.write(0);
  }
  else
  {
    servo.write(90);
  }

  delay(100); // this speeds up the simulation
}
