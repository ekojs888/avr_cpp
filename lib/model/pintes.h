#pragma once
#include <avr/io.h>

int ReadPin(uint8_t);

void initADC();

int ReadADC(uint8_t);