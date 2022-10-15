#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservoA;
Servo myservoB;
Servo myservoC;
Servo myservoD;

const int konveyor = 12;
int proximity = 32;
int ttd = 0;

int readProxi;

float A, B, C, D;
char inChar_RX1;
String inputString;

int pos = 0;

void setup() {
  Serial.begin(9600);
  myservoA.attach(2);
  myservoB.attach(3);
  myservoC.attach(4);
  myservoD.attach(5);
  lcd.begin();
  ttd = 0;
  pinMode(proximity, INPUT);
  pinMode(konveyor, OUTPUT);
  readProxi = HIGH;
}

void loop() {
  readProximity();
  ShowLCD();
  if (readProxi == HIGH) {
    digitalWrite(konveyor, LOW); //kONVEYOR MATI
    myservoA.write(90);
    myservoB.write(10);
    myservoD.write(80); //Kondisi Cap
    myservoC.write(90);
    ttd++; //Counter Jumplah Cap
    delay(1000);
    digitalWrite(konveyor, HIGH); //kONVEYOR NYALA
    myservoA.write(90);
    myservoB.write(10);
    myservoD.write(130); //Kondisi Tidak Cap
    myservoC.write(90);
    delay(1000);
    digitalWrite(konveyor, HIGH); //kONVEYOR NYALA
    myservoA.write(90);
    myservoB.write(10);
    myservoD.write(130); //Kondisi Tidak Cap
    myservoC.write(90);
  }
  else if (readProxi == LOW) {
    digitalWrite(konveyor, HIGH); //kONVEYOR NYALA
    myservoA.write(90);
    myservoB.write(10);
    myservoD.write(130); //Kondisi Tidak Cap
    myservoC.write(90);
  }
}
