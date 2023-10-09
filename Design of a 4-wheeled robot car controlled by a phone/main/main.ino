#include <SoftwareSerial.h>
SoftwareSerial blue(2, 3);// rx -2 tx -3
int ENA  = 11;
int izqA = 12; 
int izqB = 13; 

int ENB  = 5;
int derA = 6; 
int derB = 7; 
int vel = 200; // Velocidad de los motores (0-255)

int estado = 'h'; // inicia detenido

void setup() { 
Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
blue.begin(9600);
pinMode(derA, OUTPUT);
pinMode(derB, OUTPUT);
pinMode(izqA, OUTPUT);
pinMode(izqB, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
analogWrite(ENA,200);
analogWrite(ENB,200);
} 

void loop() { 
if(blue.available()>0){ // lee el bluetooth y almacena en estado
estado = blue.read();
}
   
if(estado=='e'){ // Forward
  Serial.println(estado);
digitalWrite(derB, 0); 
digitalWrite(izqB, 0); 
digitalWrite(derA, 1); 
digitalWrite(izqA, 1); 
estado = 'h';
}
if(estado=='d'){ // right
    Serial.println(estado);
digitalWrite(derB, 1); 
digitalWrite(izqB, 0); 
digitalWrite(derA, 0); 
digitalWrite(izqA, 1); 
estado = 'h';
 }
if(estado=='c'){ // Stop
    Serial.println(estado);
digitalWrite(derB, 0); 
digitalWrite(izqB, 0); 
digitalWrite(derA, 0); 
digitalWrite(izqA, 0); 
estado = 'h';
}
if(estado=='b'){ // left
    Serial.println(estado);
digitalWrite(derB, 0); 
digitalWrite(izqB, 1);
digitalWrite(izqA, 0);
digitalWrite(derA, 1); 
estado = 'h';
} 

if(estado=='a'){ // Reverse
    Serial.println(estado);
digitalWrite(derA, 0); 
digitalWrite(izqA, 0);
digitalWrite(derB, 1); 
digitalWrite(izqB, 1); 
estado = 'h';
 }
 if(estado=='f'){ // Reverse
    Serial.println(estado);
    estado = 'h';
 }
 }
