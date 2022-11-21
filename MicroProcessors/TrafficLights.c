#include <stdint.h>
#include <stm32f031x6.h>

//control functions

//lights on
void redOn(void);
void greenOn(void);
void amberOn(void);

//lights off
void greenOff(void);
void redOff(void);
void amberOff(void);
int buttonPress(void);

//delay function
void delay(volatile uint32_t dly);


int main()
{
	uint32_t count = 0;
	RCC->AHBENR |= (1 << 18) + (1<<17); //enable port B/A
	
}

void delay(volatile uint32_t dly)
{
	while(dly--);
}