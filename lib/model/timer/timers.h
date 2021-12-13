#pragma once

#include <avr/io.h>
// #include <avr/interrupt.h>

#define TAKS_INTERVAL (65536 - ((0.001 * F_CPU) / 1024))

class timers
{
public:
    timers();
    void Begin();
    bool Get();
    bool Get(int delay);
    void Clear();
    void Run();

private:
    int count = 0;
};
