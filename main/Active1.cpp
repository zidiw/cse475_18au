#include "Active1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Active1::loop(uint32_t dt) {
  Midi::setSound(random(0x01,0x12));
  int temp = random(0,3);
  uint8_t light = 0x00;
  if (temp == 0) {
    light = 0x01;
  }
  if (temp == 1) {
    light = 0x02;
  }
  if (temp == 2) {
    light = 0x08;
  }
  Neopixel::setLight(light);
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}
