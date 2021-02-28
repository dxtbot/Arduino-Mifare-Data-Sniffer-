/* Made by Dexterbot
  this part reads the the eeprom !
*/
#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C
Adafruit_SSD1306 oled(1);
#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
uint8_t address = 0;
byte value0;
byte value1;
byte value2;
byte value3;
byte value4;
uint8_t MEM_STEP = 0;
uint8_t STEP = 0;
uint8_t cards = 0;

void setup() {
   oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  Serial.begin(19200);
  Serial.println("      Starting Eeprom reading DXT Card device ");
  delay (100);
  Serial.println("          Ready to read 100 cards UID !");
  delay (1000);
  Serial.println("                   Starting "        );
  delay (1000);
  Serial.println(" OK !");
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.setCursor(17, 18);
  oled.print(" MEMREAD");
  oled.display();
  delay (1000);
  cards = EEPROM.read(150);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(10, 4);
  oled.print("! Cards in memory !");
  oled.setTextSize(2);
  oled.setCursor(17, 30);
  oled.print(cards);
  oled.display();
  Serial.print("Cards found in memory = ");
  Serial.println(cards);
  delay (1000);
  Serial.println("-----------------------------------------------------------------------------------------------");
  Serial.println("");
  oled.clearDisplay();
  EEPROM.write(150, 0); // card values
  delay(500);
  EEPROM.write(160, 0); // steps counted
  delay(500);
}

void loop() {
  // read a byte's from the current addresses of the EEPROM
  STEP = STEP + 1;
  value0 = (EEPROM.read(0 + MEM_STEP));
  value1 = (EEPROM.read(1 + MEM_STEP));
  value2 = (EEPROM.read(2 + MEM_STEP));
  value3 = (EEPROM.read(3 + MEM_STEP));
  value4 = (EEPROM.read(4 + MEM_STEP));
  Serial.print("NEXT CARD NUMBER ");
  Serial.print(STEP);
  Serial.print(" = ");
  Serial.print(value0, HEX);
  Serial.print(value1, HEX);
  Serial.print(value2, HEX);
  Serial.print(value3, HEX);
  //Serial.print(value4, HEX);
  // if (value4 != 228 || value4 != 239 || value4 != 240)Serial.print(" UNKNOWN CARD");
  if (value4 == 240)Serial.print(" MF MINICARD");
  if (value4 == 239)Serial.print(" MF 1K CARD");
  if (value4 == 228)Serial.print(" MF 4K CARD");
  MEM_STEP = MEM_STEP + 5;
  Serial.println();
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(15, 4);
  oled.print("! Reading Busy !");
  oled.setTextSize(2);
  oled.setCursor(13, 30);
  oled.print(value0, HEX);
  oled.setCursor(40, 30);
  oled.print(value1, HEX);
  oled.setCursor(67, 30);
  oled.print(value2, HEX);
  oled.setCursor(94, 30);
  oled.print(value3, HEX);
  // oled.print(value4, HEX);
  oled.display();
  delay(100);
  oled.clearDisplay();
  address = address + 1;
  if (address == cards ) {
    address = 101;
    Serial.println("! END OF MEMORY STOP READING ! ");
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(1);
    oled.setCursor(7, 4);
    oled.print("! Reading finish !");
    oled.display();
    delay(5000);
    oled.clearDisplay();
    EEPROM.write(0, 0);
    for (int i = 0 ; i < 165 ; i++) {
      EEPROM.write(i, 0);
      delay(100);
      EEPROM.write(i, 0);
      delay(100);
      Serial.println("! MEMORY FORMATING !");
    }
    oled.setTextColor(WHITE);
    oled.setTextSize(1);
    oled.setCursor(7, 4);
    oled.print("! FORMATING DONE !");
    oled.display();
    Serial.println("! FORMATING DONE !");
    delay(5000);
    return;
  }

  delay(100);
}
