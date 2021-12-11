#include "uart.h"

void serial::Begin()
{
    UART_Init(9600);
}
void serial::Begin(uint16_t baud)
{
    UART_Init(baud);
}

void serial::Print(unsigned char data)
{
    UART_Write(data);
}

void serial::Print(double data)
{
    d_double angka = calculasi_double(data, DEFAULT_NUM_DESIMAL, DEFAULT_PEMBULATAN);
    Print(angka.bulat);
    Print(".");
    Print(angka.pecahan);
}
void serial::Print(double data, int num)
{
    d_double angka = calculasi_double(data, num, DEFAULT_PEMBULATAN);
    Print(angka.bulat);
    Print(".");
    Print(angka.pecahan);
}
void serial::Print(double data, int num, uint8_t bulat)
{
    d_double angka = calculasi_double(data, num, bulat);
    Print(angka.bulat);
    Print(".");
    Print(angka.pecahan);
}
void serial::Print(int data)
{
    char dout[5];
    itoa(data, dout, 10);
    Print(dout);
}
void serial::Print(const char *data)
{
    while (*data > 0)
        UART_Write(*data++);
}
void serial::Println()
{
    Print("\n");
    Print("\r");
}
void serial::Println(const char *data)
{
    Print(data);
    Print("\n");
    Print("\r");
}

void serial::Println(double data)
{
    Print(data);
    Println();
}
void serial::Println(double data, int num)
{
    Print(data, num);
    Println();
}
void serial::Println(double data, int num, uint8_t bulat)
{
    Print(data, num, bulat);
    Println();
}

uint8_t serial::Read()
{
    return UART_Read();
}

// private
//===================

d_double serial::calculasi_double(double data, int num, uint8_t bulat)
{
    d_double angka;
    int bb = (int)data;
    double bk = data - bb;

    int number_of_digits = 0;
    angka.bulat = bb;
    do
    {
        ++number_of_digits;
        bb /= 10;
    } while (bb);

    int i = 10;
    int ac;
    for (int a = 0; a < num; a++)
    {
        ac = (bk * i);
        i = i * 10;
    };
    if (bulat == 1)
        ac = ac + 1;
    angka.pecahan = ac;
    return angka;
}

void serial::UART_Write(unsigned char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
    {
    };
    UDR0 = data;
}
uint8_t serial::UART_Read()
{
    while ((UCSR0A & (1 << RXC0)) == 0)
    {
    };           // Do nothing until data have been received
    return UDR0; // OK, return it.
}
void serial::UART_Init(uint16_t baud)
{
    uint16_t b = (((F_CPU / (baud * 16UL))) - 1);
    UBRR0H = (b >> 8);
    UBRR0L = (b & 0xff);

    // #if USE_2X
    //     UCSR0A |= (1 << U2X0);
    // #endif

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // 8-bit, 1 stop bit, no pariAty, asynchronous UART
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00) | (0 << USBS0) |
             (0 << UPM01) | (0 << UPM00) | (0 << UMSEL01) |
             (0 << UMSEL00);
}