#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); 
int quangtro = 2; 
int relay = 9;
void setup() {
lcd.init();
lcd.backlight();
pinMode(quangtro, INPUT);
pinMode(relay, OUTPUT);
}
void loop() {
lcd.clear();
int gt = digitalRead(quangtro); 
lcd.setCursor(0,0);
lcd.print("GT Quang Tro:");
lcd.setCursor(15,0);
lcd.print(gt);
if ( gt == 1) 
{
digitalWrite(relay, HIGH);//Turn on the power when it's light
}
else {digitalWrite(relay,LOW);} //Turn off 
delay(500);
}
