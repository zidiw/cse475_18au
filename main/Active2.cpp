#include "Active2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Active2::loop(uint32_t dt) {
  Midi::setSound(random(0x20,0x25));
  int temp = random(0,2);
  uint8_t light = 0x00;
  if (temp == 0) {
    light = 0x04;
  }
  if (temp == 1) {
    light = 0x13;
  }
  Neopixel::setLight(light);
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.001f;
}
