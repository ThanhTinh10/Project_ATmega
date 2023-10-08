#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16, 2);
int CBDoAm = A1; 
#define role 12 
float doamdat; 
void setup()
{
Serial.begin(9600);
lcd.init();
lcd.backlight();

pinMode(role,OUTPUT);
}
void loop()
{
doamdat=analogRead(CBDoAm);
lcd.setCursor(0,0);
lcd.print("Do am la:");
lcd.setCursor(10,0);
lcd.print(doamdat); 

if(doamdat > 800)
{
digitalWrite(role,HIGH); 
delay(2000);
}
else
{
digitalWrite(role,LOW);
}
delay(1000);
}
