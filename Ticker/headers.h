#pragma once

#include "Arduino.h"
#include <avr/wdt.h>

#define MAX_STRLEN 256

const uint8_t ARDUINO_LED = 13;
const uint8_t ROW_DATA = 2;
const uint8_t ROW_LATCH = 3;
const uint8_t ROW_CLOCK = 4;
const uint8_t COL_DATA = 8;
const uint8_t COL_LATCH = 9;
const uint8_t COL_CLOCK = 10;
