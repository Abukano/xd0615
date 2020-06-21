
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11,9,8,7,6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  if(Serial.available()>0)
  {
    lcd.clear();
    String comdata = "";
    comdata += (Serial.readString());
    delay(2);
    int num = comdata.length();
    lcd.setCursor(0, 0);
    lcd.print(comdata);
    if (num >=17)
    {
       lcd.setCursor(0, 1);
       lcd.print(comdata.substring(17, num));
    }

  }
} 