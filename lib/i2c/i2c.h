#ifndef __I2C__
#define __I2C__

#include <avr/io.h>
// #include <model.h>

#define I2C_SCL_CLK (F_CPU / (16 + 2(TWBR)*1024))
#define SDA 4
#define SCL 5
#define PORTI2C PORTC
#define DDRI2C DDRC

class i2c
{
private:
public:
    void Begin();
    void Start();
    void Write(uint8_t data);
    void Stop();
};

#endif