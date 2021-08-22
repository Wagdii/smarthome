//
#include "HC05.h"
#include "SPI.h"
//Main function
uint8_t RECEIVED_DATA;
int main(void)
{
SPI_Init();
HC05_Init();

	while (1) 
    {
	RECEIVED_DATA = HC05_Receive();
    SPI_Transmit(RECEIVED_DATA);
	}
}