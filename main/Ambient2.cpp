#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient2::loop(uint32_t dt) {
  int temp1 = random(0,3);
  uint8_t sound = 0x00;
  if (temp1 == 0) {
    sound = 0x29;
  }
  if (temp1 == 1) {
    sound = 0x2A;
  }
  if (temp1 == 2) {
    sound = 0x26;
  }
  Midi::setSound(sound);
  int temp2 = random(0,2);
  uint8_t light = 0x00;
  if (temp2 == 0) {
    light = 0x06;
  }
  if (temp2 == 1) {
    light = 0x0D;
  }
  Neopixel::setLight(light);
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
