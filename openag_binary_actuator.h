#ifndef OPENAG_BINARY_ACTUATOR_H
#define OPENAG_BINARY_ACTUATOR_H

#include "Arduino.h"
#include <std_msgs/Bool.h>

class BinaryActuator {
  public:
    // Constructor
    BinaryActuator(int pin, bool is_active_low);

    // Public variables
    bool has_error;
    char* error_msg;

    // Public functions
    void begin();
    void set_state(std_msgs::Bool state);

  private:
    // Private variables
    int _pin;
    bool _is_active_low;
};

#endif
