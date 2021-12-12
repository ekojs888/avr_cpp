#include "taks.h"

void taks::Begin()
{
}
int taks::SetTaks()
{
    int id;
    id = idTaks;
    idTaks++;
    return id;
}
bool taks::GetTaks(int id, int delay)
{
    if (CountTaks[id] > delay)
    {
        CountTaks[id] = 0;
        return true;
    }
    return false;
}
void taks::Run(bool sts) // input sts trigger 1ms , true is 1m timer
{
    if (sts)
    {
        for (int i = 0; i < idTaks; i++)
        {
            CountTaks[i]++;
        }
    }
}
