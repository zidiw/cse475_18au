#include "Startle.h"
#include "Neopixel.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 return rand() % 4 + 1; // 1 - 4
}

void Startle::loop(uint32_t dt) {
  int temp1 = random(0,2);
  uint8_t sound = 0x00;
  if (temp1 == 0) {
    sound = 0x25;
  }
  if (temp1 == 1) {
    sound = 0x27;
  }
  Midi::setSound(sound);
  int temp2 = random(0,2);
  uint8_t light = 0x00;
  if (temp2 == 0) {
    light = 0x12;
  }
  if (temp2 == 1) {
    light = 0x03;
  }
  Neopixel::setLight(light);
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}
