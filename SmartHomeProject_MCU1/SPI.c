/*
* SPI.c
*
*/


#include "SPI.h"

void SPI_Init(void)
{
	#if SPI_MODE == MASTER
	SET_BIT(SPI_PORT, MOSI);/*Define direction as output*/
	CLR_BIT(SPI_PORT, MISO);/*Define direction as input*/
	SET_BIT(SPI_PORT, CLK);/*Define direction as output*/
	SET_BIT(SPI_PORT, SS); /*Define direction as output*/
	SPCR = 0x53;//0b 0101 0011
	#elif SPI_MODE == SLAVE
	CLR_BIT(SPI_PORT, MOSI);/*Define direction as input*/
	SET_BIT(SPI_PORT, MISO);/*Define direction as output*/
	CLR_BIT(SPI_PORT, CLK);/*Define direction as input*/
	CLR_BIT(SPI_PORT, SS); /*Define direction as input*/
	SPCR = 0x43;//0b 0100 0011
	#endif
}
void SPI_Transmit(uint8_t data)
{
	SPDR = data;
	while (GET_BIT(SPSR, SPIF) != 1);
}
uint8_t SPI_Receive(void)
{
	while (GET_BIT(SPSR, SPIF) != 1);
	return SPDR;
}
void SPI_SlaveSelect(uint8_t slave)
{
	switch (slave)
	{
		case 0:
		CLR_BIT(PORTB, SS);
		break;
		case 1:
		break;
	}
}