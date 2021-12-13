#ifndef MODEL_H
#define MODEL_H

#include <avr/io.h>
#include <stdint.h>

#include "timer/timers.h"
#include "taks/taks.h"
#include "portio/modelIO.h"
#include "uart/uart.h"

#define WordLow(w) ((uint8_t)((w)&0xff))
#define WordHigh(w) ((uint8_t)((w) >> 8))

typedef uint8_t byte;

timers Timer;
serial Serial;

bool COUNT_TIMER_MS;

void Utama();
void Run();

int main(void)
{
    Timer.Begin();

    Serial.Println("===AVR CODE ejs963===");

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