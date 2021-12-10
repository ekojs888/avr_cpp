#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

class timers
{
public:
    void Begin();
    uint64_t Get(uint64_t &d);
    uint64_t Get();
    void Clear();

private:
};
