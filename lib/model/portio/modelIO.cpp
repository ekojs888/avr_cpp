#include "modelIO.h"

// int ReadPin(uint8_t pin, uint8_t bit)
// {
//     return readBit(pin, bit);
// }
void initADC()
{
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
int ReadADC(uint8_t pin)
{
    if (pin < 0 || pin > 7)
    {             // ADC0 - ADC7 is available
        return 1; // pin number is out of range
    }

    ADMUX = (ADMUX & 0xF8) | pin;
    ADCSRA |= (1 << ADSC);
    while ((ADCSRA & (1 << ADSC)) == 0)
        ;
    return ADC;
}