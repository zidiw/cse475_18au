#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient1::loop(uint32_t dt) {
  int temp1 = random(0,5);
  uint8_t sound = 0x00;
  if (temp1 == 0) {
    sound = 0x12;
  }
  if (temp1 == 1) {
    sound = 0x13;
  }
  if (temp1 == 2) {
    sound = 0x16;
  }
  if (temp1 == 3) {
    sound = 0x17;
  }
  if (temp1 == 4) {
    sound = 0x18;
  }
  Midi::setSound(sound);
  int temp2 = random(0,3);
  uint8_t light = 0x00;
  if (temp2 == 0) {
    light = 0x09;
  }
  if (temp2 == 1) {
    light = 0x0A;
  }
  if (temp2 == 2) {
    light = 0x0E;
  }
  Neopixel::setLight(light);
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}
