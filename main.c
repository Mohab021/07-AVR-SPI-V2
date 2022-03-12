
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_SPI_Declarations.h"
#define F_CPU 4000000ul

int main(void)
{
	char x;
	Pin_Direction(D, 4, output);
	Pin_Reset(D, 4);
	SPI_Slave_INT();
	
	while(1)
	{
		x = SPI_Receive();
		
		if(x == '1')
		{
			Pin_Toggle(D, 4);
		}
	}
}

