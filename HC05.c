/*
 * HC05.c
 *
  */ 
#include "HC05.h"
void HC05_Init(void)
{
	UART_Init();
}
uint8_t HC05_Receive(void)
{
	uint8_t data;
	data = UART_Receive();
	return data;
}
