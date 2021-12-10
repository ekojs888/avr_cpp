#include "config.h"

timers t;
serial s;

int main(void)
{
  SET_BIT(DDRD, PD7);
  t.Begin();
  s.Begin();

  while (1)
  {
    // delay 1 ms
    if (t.Get() >= 500)
    {
      TOGGLE_BIT(PORTD, PD7);
      s.Println("hallow");
      t.Clear();
    }
  }

  return 0;
}
