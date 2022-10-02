#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         32          
#define SS_PIN          14           
#define IRQ_PIN         2           

MFRC522 mfrc522(SS_PIN, RST_PIN);   
MFRC522::MIFARE_Key key;

void activateRec(MFRC522 mfrc522);
void clearInt(MFRC522 mfrc522);
byte regVal = 0x7F;


void setup() {
  Serial.begin(115200); 
  SPI.begin();         
  mfrc522.PCD_Init(); 
  pinMode(IRQ_PIN, INPUT_PULLUP);
  mfrc522.PCD_WriteRegister(mfrc522.ComIEnReg, regVal);
  attachInterrupt(digitalPinToInterrupt(IRQ_PIN), readCard, FALLING);

}


void loop() {
Serial.priintln("Interrupt not working") ;
} 


void readCard() {
  Serial.println("interuppt works") ;
}