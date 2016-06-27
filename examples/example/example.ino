#include <openag_binary_actuator.h>

#define PIN 6

BinaryActuator actuator(PIN, true);

void setup() {
  Serial.begin(9600);
  actuator.begin();
}

std_msgs::Bool state;

void loop() {
  if (Serial.available()) {
    state.data = (Serial.parseInt() != 0);
    actuator.set_state(state);
  }
  if (actuator.has_error) {
    Serial.print("Error: ");
    Serial.println(actuator.error_msg);
    actuator.has_error = false;
  }
}
