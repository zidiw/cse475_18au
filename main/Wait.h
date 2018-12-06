#ifndef _WAIT_H_
#define _WAIT_H_

#include "Creature.h"
#include "State.h"

class Wait : public State {
 public:
  Wait(Creature& creature) : State(creature, "Wait", WAIT) {}
  uint8_t getNumRepeats();
  State* transition() override;
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _WAIT_H_
