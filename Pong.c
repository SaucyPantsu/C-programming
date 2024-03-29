#include <stm32f031x6.h>
#include "display.h"
void initClock(void);
void initSysTick(void);
void SysTick_Handler(void);
void delay(volatile uint32_t dly);
static volatile uint32_t milliseconds;


void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber);
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);
int isInside(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t px, uint16_t py)

static const pingPong [] = {};

static const paddle [] = {};

int main()
{
    int paddleOneinverted = 0;
	int paddleTwoinverted = 0;
	int toggle = 0;
	int count = 0;
	int paddleOnemoved = 0;
	int paddleTwomoved = 0;
	uint16_t x = 50;
	uint16_t y = 50;
	uint16_t oldx = x;
	uint16_t oldy = y;
	initClock();
	initSysTick();
	RCC->AHBENR |= (1 << 18) + (1 << 17); // enable Ports A and B
	display_begin();
	pinMode(GPIOB,4,0);
	pinMode(GPIOB,5,0);
	pinMode(GPIOA,8,0);
	enablePullUp(GPIOB,4);
	enablePullUp(GPIOB,5);
	enablePullUp(GPIOA,11);
	enablePullUp(GPIOA,8);

    while(1)
    {
        paddleOnemoved = 0;
		paddleTwoinverted = 0;
		paddleOneinverted = 0;
		paddleTwomoved = 0;

		if ((GPIOB->IDR & (1 << 4))==0)
		{					
			if (x < 110)
			{
				x = x + 3;
				paddleOnemoved = 1;
				paddleOneinverted=0;
			}
			
			
		}
		if ((GPIOB->IDR & (1 << 5))==0)
		{			
			
			if (x > 10)
			{
				x = x - 3;
				paddleOnemoved = 1;
				paddleOneinverted=1;
			}			
		}
		if ( (GPIOA->IDR & (1 << 11)) == 0)
		{
			if (y < 110)
			{
				y = y + 3;
				paddleTwomoved = 1;
				paddleTwoinverted = 0;
			}

		}
		if ( (GPIOA->IDR & (1 << 8)) == 0)
		{			
			if (y > 10)
			{
				y = y - 3;
				paddleTwomoved = 1;
				paddleTwoinverted = 1;
			}
		}

		if(paddleOnemoved)
		{
			fillRectangle(oldx,oldy,12,16,0);
			oldx = x;

		}

		if (paddleTwomoved)
		{
			fillRectangle(oldx,oldy,12,16,0);
			oldx = x;
		}
		







    }
}

int isInside(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t px, uint16_t py)
{
	// checks to see if point px,py is within the rectange defined by x,y,w,h
	uint16_t x2,y2;
	x2 = x+w;
	y2 = y+h;
	int rvalue = 0;
	if ( (px >= x) && (px <= x2))
	{
		// ok, x constraint met
		if ( (py >= y) && (py <= y2))
			rvalue = 1;
	}
	return rvalue;
}

void initSysTick(void)
{
	SysTick->LOAD = 48000;
	SysTick->CTRL = 7;
	SysTick->VAL = 10;
	__asm(" cpsie i "); // enable interrupts
}

void SysTick_Handler(void)
{
	milliseconds++;
}

void initClock(void)
{
// This is potentially a dangerous function as it could
// result in a system with an invalid clock signal - result: a stuck system
        // Set the PLL up
        // First ensure PLL is disabled
        RCC->CR &= ~(1u<<24);
        while( (RCC->CR & (1 <<25))); // wait for PLL ready to be cleared
        
  // Warning here: if system clock is greater than 24MHz then wait-state(s) need to be
        // inserted into Flash memory interface
				
        FLASH->ACR |= (1 << 0);
        FLASH->ACR &=~((1u << 2) | (1u<<1));
        // Turn on FLASH prefetch buffer
        FLASH->ACR |= (1 << 4);
        // set PLL multiplier to 12 (yielding 48MHz)
        RCC->CFGR &= ~((1u<<21) | (1u<<20) | (1u<<19) | (1u<<18));
        RCC->CFGR |= ((1<<21) | (1<<19) ); 

        // Need to limit ADC clock to below 14MHz so will change ADC prescaler to 4
        RCC->CFGR |= (1<<14);

        // and turn the PLL back on again
        RCC->CR |= (1<<24);        
        // set PLL as system clock source 
        RCC->CFGR |= (1<<1);
}

void delay(volatile uint32_t dly)
{
	uint32_t end_time = dly + milliseconds;
	while(milliseconds != end_time)
		__asm(" wfi "); // sleep
}

void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber)
{
	Port->PUPDR = Port->PUPDR &~(3u << BitNumber*2); // clear pull-up resistor bits
	Port->PUPDR = Port->PUPDR | (1u << BitNumber*2); // set pull-up bit
}

void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode)
{
	uint32_t mode_value = Port->MODER;
	Mode = Mode << (2 * BitNumber);
	mode_value = mode_value & ~(3u << (BitNumber * 2));
	mode_value = mode_value | Mode;
	Port->MODER = mode_value;
}