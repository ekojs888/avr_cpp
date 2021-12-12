#include "timers.h"

// uint64_t count;
// uint64_t tcntval = 65536 - ((0.001 * F_CPU) / 1024);
timers::timers()
{
    Begin();
}
void timers::Begin()
{
    TCCR1A = 0x00;                        // Normal mode of operation
    TCCR1B = ((1 << CS10) | (1 << CS12)); // 1024 prescaler
    TCNT1 = TAKS_INTERVAL;
}

bool timers::Get()
{
    if (count >= 1)
    {
        count = 0;
        return true;
    }
    return false;
}

bool timers::Get(int delay)
{
    if (count > delay)
    {
        count = 0;
        return true;
    }
    return false;
}

void timers::Clear()
{
    count = 0;
}

void timers::Run()
{
    if ((TIFR1 & (1 << TOV1)) == 1)
    {
        count++;
        //===============
        TCNT1 = TAKS_INTERVAL;
        TIFR1 |= (1 << TOV1);
    }
}

// ISR(TIMER1_OVF_vect)
// {
//     count[0]++;
//     // for (int b = 0; b < numCount; b++)
//     // {
//     //     count[b]++;
//     // }
//     TCNT1 = TAKS_INTERVAL;
// }