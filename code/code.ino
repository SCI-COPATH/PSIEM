#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;
#define DHT11_PIN 6
#define CO2 A0
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  pinMode(CO2,INPUT);
  lcd.begin(16,4);
  pinMode(CO2,INPUT);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp:");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(DHT.humidity);
  lcd.print("%");
  if(digitalRead(CO2)==HIGH){
    lcd.setCursor(0,3);
    lcd.print("C02 Detected");
    delay(700);
    lcd.setCursor(0,3);
    lcd.print("              ");
    delay(700);
  }else{
    delay(1000);
  }
}
