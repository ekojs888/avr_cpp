#ifndef MODEL_H
#define MODEL_H

#include <avr/io.h>
#include <stdint.h>
// #include <uart.h>
#include <timers.h>
#include <taks.h>

#include "pintes.h"
#include "uart.h"

timers Timer;
serial Serial;

#define TOGGLE_BIT(PORT, BIT) PORT ^= (1 << BIT)
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)

bool COUNT_TIMER_MS;

void Utama();
void Run();

int main(void)
{
    Timer.Begin();

    Serial.Println("===EKOJS999===");

    Utama();
    while (1)
    {
        COUNT_TIMER_MS = Timer.Get();
        Run();
        Timer.Run();
    }
    return 0;
}

#endif // MODEL_H end