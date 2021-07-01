#include "DHT.h"
#include <dht.h>
#define DHTPIN 6 
#include <LiquidCrystal.h>
#define DHTTYPE DHT11 
#define DHT11_PIN 6
DHT dht(DHTPIN, DHTTYPE);
#define CO2 A0
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
void setup(){
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  lcd.begin(16,4);
  pinMode(CO2,INPUT);
  dht.begin();
}

void loop(){
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
   // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.setCursor(0,0); 
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.print("%");
  if(digitalRead(CO2)==HIGH){
    lcd.setCursor(0,3);
    lcd.print("C02 Detected");
    delay(100);
    lcd.setCursor(0,3);
    lcd.print("              ");
    delay(100);
  }else{
    delay(2000);
  }
}
