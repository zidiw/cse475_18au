#include "Ambient3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient3::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient3::loop(uint32_t dt) {
  Midi::setSound(random(0x14,0x16));
  int temp2 = random(0,2);
  uint8_t light = 0x00;
  if (temp2 == 0) {
    light = 0x07;
  }
  if (temp2 == 1) {
    light = 0x10;
  }
  Neopixel::setLight(light);
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 0.001f;
}
