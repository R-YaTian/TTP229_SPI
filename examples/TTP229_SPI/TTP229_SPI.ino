//
// Created by bratoff on 27.06.21.
// Based on TTP229 by kiryanenko.
//


//////////////////////////////////////////////////////////////////
// Connections
//
// - Uno:
//     - SDO <-> 12 (MISO)
//     - SCL <-> 13 (SCK)
//
// - Mega:
//     - SDO <-> 50 (MISO)
//     - SCL <-> 52 (SCK)
//
// - Leo:
//     - SDO <-> ICSP-1 (MISO)
//     - SCL <-> ICSP-3 (SCK)
//
// - ATMegaZero:
//     - SDO <-> 14 (MISO)
//     - SCL <-> 15 (SCK)
//
//////////////////////////////////////////////////////////////////


#include <SPI.h>
#include <TTP229_SPI.h>

#define SCK_PIN D5
#define MISO_PIN D6

// Uncomment for true SPI
TTP229_SPI ttp229;
// Uncomment for bitbang on SCK_PIN and MISO_PIN (defined above)
//TTP229_SPI ttp229(SCK_PIN, MISO_PIN);


void setup()
{
  ttp229.begin();
  Serial.begin(115200);
}

void loop()
{
  ttp229.readKeys();

  Serial.print("Key states: ");
  for (int i = 0; i < 16; ++i) {
    if (ttp229.isKeyPress(i)) {
      Serial.print("1 ");
    } else {
      Serial.print("0 ");
    }
  }

  int key = ttp229.getKey();
  Serial.print("Pressed key: ");
  Serial.print(key);

  Serial.print("   ");
  if (ttp229.isKeyDown(0)) {
    Serial.print("Key 0 is down");
  } else if (ttp229.isKeyUp(0)) {
    Serial.print("Key 0 is up");
  }

  Serial.println();
  delay(500);
}
