#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD at address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
String inputString = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Waiting...");
}

void loop() {
  if (stringComplete) {
    Serial.println("Received: " + inputString);

    inputString.trim(); // Clean whitespace

    lcd.clear();

    int separatorIndex = inputString.indexOf(';');

    if (separatorIndex > 0) {
      String team1Part = inputString.substring(0, separatorIndex);
      String team2Part = inputString.substring(separatorIndex + 1);

      int colonIndex1 = team1Part.indexOf(':');
      int colonIndex2 = team2Part.indexOf(':');

      if (colonIndex1 > 0 && colonIndex2 > 0) {
        String name1 = team1Part.substring(0, colonIndex1);
        String score1 = team1Part.substring(colonIndex1 + 1);

        String name2 = team2Part.substring(0, colonIndex2);
        String score2 = team2Part.substring(colonIndex2 + 1);

        // Shorten names
        name1 = name1.substring(0, min(name1.length(), 6));
        name2 = name2.substring(0, min(name2.length(), 6));

        // Clean first line
        lcd.setCursor(0, 0);
        lcd.print("                "); // 16 spaces to clear
        lcd.setCursor(0, 0);
        lcd.print(name1 + " " + score1 + "-" + score2 + " " + name2);
      } else {
        lcd.print("Bad Format");
      }
    } else {
      lcd.print("Bad Format");
    }

    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar == '\r') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}
