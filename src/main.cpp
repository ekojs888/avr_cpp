#include "config.h"

#include <timers.h>
#include <taks.h>

serial s;
taks tax;
timers timer;

int main(void)
{
  SET_BIT(DDRD, PD7);
  SET_BIT(DDRD, PD6);

  timer.Begin();
  s.Begin();
  tax.Begin();

  int id = tax.SetTaks();
  s.Println(id);
  while (1)
  {
    if (tax.GetTaks(id, 1000))
    {
      TOGGLE_BIT(PORTD, PD7);
    }

    tax.Run(timer.Get());
    timer.Run();
  }
  return 0;
}
