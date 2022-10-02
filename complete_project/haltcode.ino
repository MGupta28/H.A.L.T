#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>


#define ir1a 11
#define ir1b 2

#define ledr1 7
#define ledg1 8

constexpr uint8_t RST_PIN = 6;
constexpr uint8_t SS_PIN =  10;
int val = 0 ;

Servo myservo;

int base_time = 5;
int ir_const1 = 5;
int ir_const2 = 5;
int A=0,B=0,C=0,D=0;
int pos = 0 ;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {

  SPI.begin(); 

  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.setCursor(0,1);
  lcd.print("Timer:  ");

  attachInterrupt(digitalPinToInterrupt(3),rfid_sensor, CHANGE);

  pinMode(ledr1,OUTPUT); // 1 red
  pinMode(ledg1,OUTPUT); // 1 green
 
  pinMode(ir1a,INPUT); // A ir sensor
  pinMode(ir1b,INPUT); // B ir sensor

  myservo.attach(9);

}

void print_lcd(int t)
 {
  for(int i = t; i>= 0 ; i--)
  {
    lcd.setCursor(7,1);
    lcd.print(i);
    delay(1000);
    } 
  }



void rfid_sensor()
{
  digitalWrite(ledr1,LOW);
  digitalWrite(ledg1,HIGH);
  int time_1 = 10 ;
  Serial.print(time_1);

  myservo.write(0);

   print_lcd(time_1); 

  myservo.write(180);


}





void loop() {

  A = !digitalRead(ir1a);
  B = !digitalRead(ir1b);

  Serial.print(A);
  Serial.print(B);

  lcd.setCursor(0,0);
  lcd.print("1A=");
  lcd.print(A);
  lcd.print("1B=");
  lcd.print(B);

  digitalWrite(ledr1,LOW);
  digitalWrite(ledg1,HIGH);
  int time_1 = base_time + Air_const1 + Bir_const2 ;
  Serial.print(time_1);

  myservo.write(0);

   print_lcd(time_1); 

  myservo.write(180);


  C = 0;
  D = 0;

  digitalWrite(ledg1,LOW);
  digitalWrite(ledr1,HIGH);

  int time_2 = base_time + Cir_const1 + Dir_const2;
  Serial.print(time_2);
  print_lcd(time_2);


}
