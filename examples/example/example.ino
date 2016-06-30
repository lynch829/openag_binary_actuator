#include <openag_binary_actuator.h>

#define PIN 4

BinaryActuator actuator(PIN, false);

void setup() {
  Serial.begin(9600);
  actuator.begin();
}

std_msgs::Bool cmd;

void loop() {
  actuator.update();

  if (Serial.available()) {
    int res = Serial.parseInt();
    Serial.println(res);
    cmd.data = res != 0;
    actuator.set_cmd(cmd);
  }
  if (actuator.has_error) {
    Serial.print("Error: ");
    Serial.println(actuator.error_msg);
    actuator.has_error = false;
  }
}
