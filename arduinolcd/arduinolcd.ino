#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C de ton écran LCD (à ajuster si besoin)

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // ✅ 16 columns, 2 rows
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("En attente Qt...");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');

    // Format attendu : Real:2;Barca:1
    int sep1 = data.indexOf(':');
    int sep2 = data.indexOf(';');
    int sep3 = data.indexOf(':', sep2);

    if (sep1 != -1 && sep2 != -1 && sep3 != -1) {
      String team1 = data.substring(0, sep1);
      String score1 = data.substring(sep1 + 1, sep2);
      String team2 = data.substring(sep2 + 1, sep3);
      String score2 = data.substring(sep3 + 1);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(team1 + ":" + score1);
      lcd.setCursor(0, 1);
      lcd.print(team2 + ":" + score2);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Format Invalide");
    }
  }
}
