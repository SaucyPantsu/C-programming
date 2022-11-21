/*Microprocessors assignment 2, Pong style game
	this code is a game, similar to pong, that can be played on the sti microprocessor with a display and four buttons

*/


//libraries
#include <stm32f031x6.h>
#include "display.h"

//function prototypes
void initClock(void);
void initSysTick(void);
void SysTick_Handler(void);
void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber);
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);
void delay(volatile uint32_t dly);
int isInside(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t px, uint16_t py);

//static global ints
static volatile uint32_t milliseconds;

//images
//red ping pong paddle
static const uint16_t redracket[] = {40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,
	40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224,40224};

//blue ping pong paddle
static const uint16_t blueracket[] = {1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,
	1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994,1994};

//the ping pong ball
static const uint16_t ball[] = {0,0,65535,65535,65535,65535,65535,65535,0,0,0,0,65535,65535,65535,65535,65535,
	65535,0,0,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,
	65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,
	65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,
	65535,65535,65535,65535,65535,65535,65535,65535,0,0,65535,65535,65535,65535,65535,65535,0,0,0,0,65535,65535,
	65535,65535,65535,65535,0,0,};

int main()
{
	//initialising code and pins
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
	//score
	int blueScore = 0;
	int redScore = 0;
	//collision checking ints
	int ifHitRed = 0;
	int ifHitBlue = 0;
	
	int redInverted = 0;
	int blueInverted = 0;
	int toggle = 0;
	//int count = 0;
	int redMoved = 0;
	int blueMoved = 0;

	//paddle start positions
	uint16_t redx = 10;
	uint16_t bluex = 10;
	//previous paddle positions
	uint16_t oldrx = redx;
	uint16_t oldbx = bluex;
	//position of the paddle centres
	int blueCentre = 0;
    int redCentre = 0;

	//ball stating position
	uint16_t bally = 73;
	uint16_t ballx = 40;
	//previous ball position
	uint16_t oldbally = bally;
	uint16_t oldballx = ballx;
	
	//knowing what direction the ball is heading so bounce can be controlled
	int direction = 1; //Y direction
	int dirx = 1; //X direction
	
	while(1)
	{
		ifHitRed = 0;
		ifHitBlue = 0;
		//fill in coordiates that the ball was in last cycle
		fillRectangle(oldballx, oldbally, 10, 10, 0); 

		//old ball position is now the position ball started in in current cycle
		oldbally = bally;
		oldballx = ballx;
		redMoved = blueMoved = 0;
		redInverted = blueInverted = 0;

		//checking buttons for controlling paddle movement
		if ((GPIOB->IDR & (1 << 4))==0)
		{		
			//screen is 120 pixels wide, but as paddle is 35 wide, the left corner of the paddle is at 85 when it reaches the edge			
			if (redx < 85)
			{
				redx = redx + 2;
				redMoved = 1;
				redInverted=0;
			}
		}
		if ((GPIOB->IDR & (1 << 5))==0)
		{			
		
			if (redx > 10)
			{
				redx = redx - 2;
				redMoved = 1;
				redInverted=1;
			}			
		}

		if ( (GPIOA->IDR & (1 << 11)) == 0)
		{
			//screen is 120 pixels wide, but as paddle is 35 wide, the left corner of the paddle is at 85 when it reaches the edge	
			if (bluex < 85)
			{
				bluex = bluex + 2;
				blueMoved = 1;
				blueInverted=0;
			}
		}

		if ( (GPIOA->IDR & (1 << 8)) == 0)
		{			
			if (bluex > 10)
			{
				bluex = bluex - 2;
				blueMoved = 1;
				blueInverted = 1;
			}
		}
		
		//painting ball image on the screen
		putImage(oldballx,oldbally,10,10,ball,0,0);
		
		//ball direction of bounce code of x axis walls
		if(bally < 15)
		{
			direction = 1; //bottom heading to top
		}

		else if(bally > 135)
		{
			direction = 0; //top heading to bottom
		}

		// checking ball bounce direction on walls of y axis
		if(ballx < 1)
		{
			dirx = 0; //left wall heading to right wall
		}
		else if(ballx > 115)
		{
			dirx =1; //right wall heading to left wall
		}
		
		if(direction == 0) //top to bottom
		{
			bally = bally -5;
			if(dirx == 0)
			{
				ballx = ballx + 4;
			}
			else if(dirx == 1)
			{
				ballx = ballx - 4;
			}
		}
		
		else if (direction == 1)//bottom to top
		{
			bally = bally +5;
			if(dirx == 0) 
			{
				ballx = ballx + 4;
			}
			else if(dirx == 1)
			{
				ballx = ballx - 4;
			}
		}
		
		if ((redMoved)|| (blueMoved))
		{
			fillRectangle(oldrx,5,35,5,0);
			fillRectangle(oldbx,150,35,5,0);
			oldrx = redx;
			oldbx = bluex;					
			if (redMoved)
			{
				if (toggle){
					putImage(redx,5,35,5,redracket,redInverted,0);
					putImage(bluex,150,35,5,blueracket,blueInverted,0);
				}
				else{
					putImage(redx,5,35,5,redracket,redInverted,0);
					putImage(bluex,150,35,5,blueracket,blueInverted,0);
				}
				toggle = toggle ^ 1;
			}
			else if (blueMoved)
			{
				if (toggle){
					putImage(bluex,150,35,5,blueracket,blueInverted,0);
					putImage(redx,5,35,5,redracket,redInverted,0);
				}
				else{
					putImage(bluex,150,35,5,blueracket,blueInverted,0);
					putImage(redx,5,35,5,redracket,redInverted,0);
				}
					
				toggle = toggle ^ 1;
			}
		}

		// finding centre of paddle to check for collissions with the ball
		blueCentre = bluex + 18;
		redCentre = redx + 18;

		if(ballx - blueCentre < 18 || blueCentre - ballx <18)
		{
			ifHitBlue = 1;
		}

		if(ballx - redCentre < 18 || redCentre - ballx <18)
		{
			ifHitRed = 1;
		}

		//collision code
		if(bally > 135 && ifHitBlue == 1)
		{
			blueScore = blueScore + 1;
		}
		if(bally < 5 && ifHitRed == 1)
		{
			redScore = redScore + 1;

		}
		delay(50);
	}
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
	/*
	*/
	uint32_t mode_value = Port->MODER;
	Mode = Mode << (2 * BitNumber);
	mode_value = mode_value & ~(3u << (BitNumber * 2));
	mode_value = mode_value | Mode;
	Port->MODER = mode_value;
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
