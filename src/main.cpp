#include <model.h>

taks tax1;
taks tax2;
int id1, id2, id3, id4;

void Utama()
{
  initADC();

  id1 = tax1.SetTaks();
  id2 = tax1.SetTaks();
  id3 = tax2.SetTaks();
  id4 = tax2.SetTaks();

  SET_BIT(DDRD, PD7);
  SET_BIT(DDRD, PD6);
  SET_BIT(DDRD, PD5);
  SET_BIT(DDRD, PD4);
  CLR_BIT(DDRD, PD2);
  SET_BIT(PORTD, PD2);

  int a = ReadPin(PIND, PD2);
  Serial.Println(a);
}

void Run()
{

  if (tax1.GetTaks(id1, 100))
  {
    TOGGLE_BIT(PORTD, PD7);
  }

  if (tax1.GetTaks(id2, 200))
  {
    TOGGLE_BIT(PORTD, PD6);
  }
  if (tax2.GetTaks(id3, 300))
  {
    TOGGLE_BIT(PORTD, PD5);
  }

  if (tax2.GetTaks(id4, 400))
  {
    TOGGLE_BIT(PORTD, PD4);
    int adc = ReadADC(0);
    Serial.Print(adc);
    Serial.Println();
  }

  tax1.Run(COUNT_TIMER_MS);
  tax2.Run(COUNT_TIMER_MS);
}
