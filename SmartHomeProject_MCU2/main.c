
#include "SPI.h"
#include "LED.h"
//Main function
uint8_t RECEIVED_DATA;
int main(void)
{
    SPI_Init();
	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	while (1) 
    {
    RECEIVED_DATA=SPI_Receive();
	switch(RECEIVED_DATA)
	{
		case '0':
		LED0_TGL();
		break;
		case '1':
		LED1_TGL();
		break;
		case '2':
		LED2_TGL();
		break;
	}
	
	}
}