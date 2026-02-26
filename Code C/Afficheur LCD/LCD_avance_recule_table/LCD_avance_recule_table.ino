// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

//   The circuit:
//  * LCD RS pin to digital pin 12
//  * LCD Enable pin to digital pin 11
//  * LCD D4 pin to digital pin 5
//  * LCD D5 pin to digital pin 4
//  * LCD D6 pin to digital pin 3
//  * LCD D7 pin to digital pin 2
//  * LCD R/W pin to ground
//  * LCD VSS pin to ground
//  * LCD VCC pin to 5V

//Sans module bus I2C : 
const int RS = 12, E = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

//Avec module I2C
// LiquidCrystal_I2C lcd(0x3E, 16, 2);
// LiquidCrystal_I2C lcd(0x34, 16, 2); 

int BP1 = 6;
int BP2 = 7;
int nbr_tab_avancer = 0;
int nbr_tab_revenir = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  // lcd.init();
  lcd.begin(16, 2);
  // lcd.clear();         
  // lcd.backlight();    
  // lcd.begin(16, 2);
  pinMode(BP1, INPUT);
  pinMode(BP2, INPUT);
  // lcd.setCursor(0, 0);
  lcd.print("--LCD Start--");
  delay(2000);
  // lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
      lcd.print("Nbr d'avance: ");
      lcd.setCursor(14, 0);
      lcd.print(nbr_tab_avancer);
      lcd.setCursor(0, 1);
      lcd.print("Nbr de recule: ");
      lcd.setCursor(15, 1);
      lcd.print(nbr_tab_revenir);

  if (digitalRead(BP1)==HIGH && nbr_tab_avancer<3) {
    nbr_tab_avancer++ ;
    nbr_tab_revenir = 0;
    delay(500);
  }

  if (digitalRead(BP2)==HIGH && nbr_tab_revenir<3) {
    nbr_tab_revenir++ ;
    nbr_tab_avancer = 0;
    delay(500);
  }

}

