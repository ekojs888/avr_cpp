#include "timers.h"

uint64_t count;
uint64_t tcntval = 65536 - ((0.001 * F_CPU) / 1024);

void timers::Begin()
{

    TCCR1A = 0x00; // Normal mode of operation
    // TCNT1 = 64754;  // over flow after 1 sec calculated at 8 MHZ
    TCNT1 = tcntval;
    TCCR1B = ((1 << CS10) | (1 << CS12)); // 1024 prescaler
    TIMSK1 |= 1 << TOIE1;                 // Enable timer1 overflow interrupt
    sei();
}

uint64_t timers::Get(uint64_t &d)
{
    count = d;
    return count;
}
uint64_t timers::Get()
{
    TIMSK1 |= 1 << TOIE1;
    return count;
}
void timers::Clear()
{
    count = 0;
}

ISR(TIMER1_OVF_vect)
{
    count++;
    // TCNT1 = 64754; // reset to over flow after 1 sec calculated at 8 MHZ
    TCNT1 = tcntval;
}