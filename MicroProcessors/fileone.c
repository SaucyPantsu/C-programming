#include <stm32f031x6.h>
void delay(volatile uint32_t dly)
{
	while(dly--);
}

int main()
{
	RCC->AHBENR = RCC->AHBENR | (1 << 18); //enable port B
	GPIOB -> MODER = GPIOB->MODER & ~ (1u << 7); //make bit 3 an output
	GPIOB -> MODER = GPIOB->MODER | (1u << 6);
	while(1)
	{
		GPIOB->ODR = (1<<3); //led on
		delay(100000);
		GPIOB->ODR = 0;//led off
		delay(100000);
	}
	
}
