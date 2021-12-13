#include <model.h>

taks tax1;
taks tax2;
int id1, id2, id3, id4;

#ifdef _BOARD_ESP32_

#endif

#ifdef _BOARD_UNO_

#endif

void Utama()
{
  initADC();

  id1 = tax1.SetTaks();
  id2 = tax1.SetTaks();
  id3 = tax2.SetTaks();
  id4 = tax2.SetTaks();

  setBit(DDRD, PD7);
  setBit(DDRD, PD6);
  setBit(DDRD, PD5);
  setBit(DDRD, PD4);
  clrBit(DDRD, PD2);
  setBit(PORTD, PD2);

  // SET_BIT(DDRC, PC0);
  setBit(PORTC, PC0);

  int a = readBit(PIND, PD2);
  Serial.Println(a);
}

void Run()
{

  if (tax1.GetTaks(id1, 100))
  {
    toggleBit(PORTD, PD7);
  }

  if (tax1.GetTaks(id2, 200))
  {
    toggleBit(PORTD, PD6);
  }
  if (tax2.GetTaks(id3, 300))
  {
    toggleBit(PORTD, PD5);
  }

  if (tax2.GetTaks(id4, 400))
  {
    toggleBit(PORTD, PD4);
    int adc = ReadADC(0);
    Serial.Print(adc);
    Serial.Println();
  }

  tax1.Run(COUNT_TIMER_MS);
  tax2.Run(COUNT_TIMER_MS);
}
