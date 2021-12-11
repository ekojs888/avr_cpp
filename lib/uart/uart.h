#pragma once

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#define RX_READY (UCSR0A & UDRE0) // check bit7 of UCSRA0
#define TX_READY (UCSR0A & 0x20)  // check bit5 of UCSRA0

#define DEFAULT_NUM_DESIMAL 3 // 3 angka di belakang koma
#define DEFAULT_PEMBULATAN 0  // pembulatan ke bawah

// #define BAUD_PRESCALE ((F_CPU / (16UL * 9600)) - 1)
struct d_double
{
    int bulat;
    int pecahan;
};

class serial
{
private:
    void UART_Write(uint8_t data);
    uint8_t UART_Read();
    void UART_Init(uint16_t baud);
    void UART_Init();
    d_double calculasi_double(double data, int num, uint8_t bulat);

public:
    void Begin();
    void Begin(uint16_t baud);
    void Print(unsigned char data);
    void Print(int data);
    void Print(const char *data);
    void Print(double data);
    void Print(double data, int num);
    void Print(double data, int num, uint8_t bulat); // bulat = 0 kebawah, bulat = 1 bulat ke atas
    void Println();
    void Println(const char *data);
    void Println(double data);
    void Println(double data, int num);
    void Println(double data, int num, uint8_t bulat); // bulat = 0 kebawah, bulat = 1 bulat ke atas

    uint8_t Read();
};
