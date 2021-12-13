#pragma once
#include <avr/io.h>

#define readBit(PORT, BIT) (((PORT) >> (BIT)) & 0x01)
#define toggleBit(PORT, BIT) PORT ^= (1 << BIT)
#define setBit(PORT, BIT) PORT |= (1 << BIT)
#define clrBit(PORT, BIT) PORT &= ~(1 << BIT)

// int ReadPin(uint8_t, uint8_t);

void initADC();

int ReadADC(uint8_t);