
#ifndef AVR_SPI_DECLARATIONS_H_
#define AVR_SPI_DECLARATIONS_H_

void SPI_Master_INT(void);
void SPI_Slave_INT(void);
void SPI_Transmit(unsigned char data);
unsigned char SPI_Receive(void);

#endif /* AVR_SPI_DECLARATIONS_H_ */