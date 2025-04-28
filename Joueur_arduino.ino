#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

byte readCard[4];
String MasterTag = "536159AD"; // badge autorisé
String tagID = "";
bool valide = false;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if (getID()) {
    if (tagID == MasterTag) {
      valide = true;
      Serial.println("ACCES_AUTORISE");
    } else {
      valide = false;
      Serial.println("ACCES_REFUSE");
    }
    delay(2000);
  }
}
 
bool getID() {
  if (!mfrc522.PICC_IsNewCardPresent()) return false;
  if (!mfrc522.PICC_ReadCardSerial()) return false;

  tagID = "";
  for (byte i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
    if (readCard[i] < 0x10) tagID += "0";
    tagID += String(readCard[i], HEX);
  }
  
  tagID.toUpperCase();
  mfrc522.PICC_HaltA();
  return true;
}
