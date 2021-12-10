#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <timers.h>
#include <uart.h>

#ifndef __CONFIG__
#define __CONFIG__

#define TOGGLE_BIT(PORT, BIT) PORT ^= (1 << BIT) // this will flip the bit
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)

#endif