#include "i2c.h"

void i2c::Begin()
{
    TWSR = 0;
    TWBR = 0x07;
    TWCR |= (1 << TWEN);
}

void i2c::Start()
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (readBit(TWCR, TWINT) == 0)
        ;
}

void i2c::Write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (readBit(TWCR, TWINT) == 0)
        ;
}

void i2c::Stop()
{
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
}