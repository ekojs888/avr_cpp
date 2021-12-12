#ifndef __TAKS__
#define __TAKS__
#include <avr/io.h>

// #include <avr/interrupt.h>

#define MAX_TAKS 5

#define t_Bit(PORT, BIT) PORT ^= (1 << BIT)
// #define TAKS_INTERVAL (65536 - ((0.001 * F_CPU) / 1024))

class taks
{
private:
    int CountTaks[MAX_TAKS];
    int idTaks = 0;

public:
    void Begin();
    int SetTaks();
    bool GetTaks(int id, int delay);
    void Run(bool sts);
};

#endif