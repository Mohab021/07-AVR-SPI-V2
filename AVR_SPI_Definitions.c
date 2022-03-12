
#include <avr/io.h>
#include "AVR_SPI_Declarations.h"

void SPI_Master_INT()
{
	DDRB = 0xB0;	// B4, B5 and B7 are Output (DDRX = 1) (SS', MOSI, SCK) = 10110000 = 0xB0
	SPCR = 0x53; //SPI is Enabled, LSB is transmitted first, Master SPI, SCK is low when idle, Sample in Leading Edge, FOSC/128 = 01010011 = 0x53
	SPSR = 0x00; //Flag is reset (put to zero), and FOSC/128 is used
}

void SPI_Slave_INT()
{
	DDRB = 0x20;	// Only B6 is Output (DDRX = 1) (MISO) = 00100000 = 0x40
	SPCR = 0x43; //SPI is Enabled, LSB is transmitted first, Slave SPI, SCK is low when idle, Sample in Leading Edge, FOSC/128 = 01000011 = 0x43
	SPSR = 0x00; //Flag is reset (put to zero), and FOSC/128 is used
}

void SPI_Transmit(unsigned char data)
{
	SPDR = data; //Send data to the Data Register
	while( !(SPSR & (1<<7)) ) ; //Flag must be 1, to ensure that data transmission is completed before sending again
}

unsigned char SPI_Receive()
{
	while( !(SPSR & (1<<7)) ) ; //Flag must be 1, to ensure that data transmission is completed and ready to be read
	return SPDR; //Return the data from the Data Register
}
