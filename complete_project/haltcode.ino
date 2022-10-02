#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 14
#define RST_PIN 32
#define IRQ_PIN 2

MFRC522 mfrc522(SS_PIN, RST_PIN); 
MFRC522::MIFARE_Key key;
void activateRec(MFRC522 mfrc522);
void clearInt(MFRC522 mfrc522);

Servo myservo; 
int pos = 0; 

int IR_1 = 13 ;
int IR_2 = 12 ;

int IR_val_1 =0 ; 
int IR_val_2 = 0 ;

int Green_led = 27 ;
int Red_led = 26 ;

int base_delay = 5000 ;


int servo_base_time = 10000 ; 
int current_time = millis();

void setup() {

  pinMode(IR_1, INPUT); 
  pinMode(IR_2, INPUT);
  
  myservo.attach(4); 
  
  Serial.begin(115200);
  
  SPI.begin();          
  mfrc522.PCD_Init(); 
  pinMode(IRQ_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(IRQ_PIN), readCard, FALLING);
  
  pinMode(Green_led,OUTPUT);
  pinMode(Red_led,OUTPUT);
  
 
}

void loop() {
  Normal_function(base_delay);
  if (digitalRead(IR_1) == LOW ){
     Normal_function(base_delay+5000);
  }
   if (digitalRead(IR_2) == LOW ){
     Normal_function(base_delay+10000);
  }
}


// Interupt if  rfid card read something 
void readCard(){
  myservo.write(90);
  digitalWrite(Green_led , HIGH);
  digitalWrite(Red_led , LOW);    
}



// Normal Code Working 
void Normal_function(int delay_time ){            
   for (pos = 0; pos <= 90; pos += 1) {            
      myservo.write(pos);             
      delay(15);  
    }
  digitalWrite(Green_led , HIGH);
  digitalWrite(Red_led , LOW);
  delay(delay_time) ;
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                      
  }
  digitalWrite(Green_led ,LOW);
  digitalWrite(Red_led , HIGH);
  delay(base_delay) ;
}