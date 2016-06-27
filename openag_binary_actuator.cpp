#include "openag_binary_actuator.h"

BinaryActuator::BinaryActuator(int pin, bool is_active_low) {
  _pin = pin;
  _is_active_low = is_active_low;
}

void BinaryActuator::begin() {
  pinMode(_pin, OUTPUT);
}

void BinaryActuator::set_state(std_msgs::Bool state) {
  if (state.data ^ _is_active_low) {
    digitalWrite(_pin, HIGH);
  }
  else {
    digitalWrite(_pin, LOW);
  }
}
