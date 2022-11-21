//MICROPROCESSOR MUSIC CONTROL CODE

//library include
#include <stdint.h>
#include <stm32f031x6.h>

//Definitions
#define DELAY 2000000
#define BUZZDELAY 1000

//FUNCTION PROTOTYPES

//control functions
//enable pinmode settings
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);
void enablePullUp(GPIO_TypeDef *Port,uint32_t BitNumber);

int buttonPress(void);
int button2Press(void);


//bit set
void setBit(volatile uint32_t *locn, uint32_t bitnumber);

void clearBit(volatile uint32_t *locn, uint32_t bitnumber);

int getBit(volatile uint32_t *locn, uint32_t bitnumber);

//delay function
void delay(volatile uint32_t dly);

//music functions
void playNote(uint32_t freq, uint32_t duration);
//buzzer
void buzzerNoise(int time);
void stopBuzz(void);



int main()
{
	int time = 1000;
	
	RCC->AHBENR |= (1 << 18) + (1<<17); //enable port B/A
	
	
	//output PINS
	pinMode(GPIOA,0,1);//Pin A0 output
	pinMode(GPIOA,1,1);//Pin A1 output
	pinMode(GPIOA,2,1);//Pin A2 output
	pinMode(GPIOA,7,1);//buzzer pin output
	
	
	//input PINS
	pinMode(GPIOB,4,0);//Pin B4 input
	
	if(buttonPress() == 1)
	{
		playNote(412,10);
	}
	else
	{
		playNote(824,10);
	}
}

//play sounds
void playNote(uint32_t freq, uint32_t duration)
{
	int count = 0;
	while(count < duration)
	{
		GPIOA->ODR = GPIOA->ODR |= (1<<7);
		delay(freq);
		GPIOA->ODR = GPIOA->ODR &= ~(1u<<7);
		delay(freq);
		count++;
	}
}
//buzzer logic
void buzzerNoise(int time)
{
	int count = 0;
	while(count < 1000)
	{
		GPIOA->ODR = GPIOA->ODR |= (1<<7);
		delay(time);
		GPIOA->ODR = GPIOA->ODR &= ~(1u<<7);
		delay(time);
		count++;
	}
}
void stopBuzz()
{
	GPIOA->ODR = GPIOA->ODR &= ~(1u<<7);
}

//button logic
int buttonPress()
{
	if((GPIOB -> IDR & 16u) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int button2Press()
{
	if((GPIOB -> IDR & 32u) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//pinMode function
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode)
{
	uint32_t mode_value = Port->MODER;
	Mode = Mode << (2 * BitNumber);
	mode_value = mode_value & ~(3u << (BitNumber * 2));
	mode_value = mode_value | Mode;
	Port->MODER = mode_value;
}

//setpin
void setBit(volatile uint32_t *locn, uint32_t bitnumber)
{
	uint32_t value;
	uint32_t mask;
	value = *locn; //read current value
	mask = (1<<bitnumber);//create mask to shift value location
	value = value | mask; //value == value OR mask
	*locn = value;
}

void clearBit(volatile uint32_t *locn, uint32_t bitnumber)
{
	uint32_t value;
	uint32_t mask;
	value = *locn; //read current value
	mask = (1<<bitnumber);//create mask to shift value location
	mask = ~mask;//invert mask
	value = value & mask; //value == value AND mask
	*locn = value;
}

int getBit(volatile uint32_t *locn, uint32_t bitnumber)
{
	uint32_t value;
	uint32_t mask;
	value = *locn; //read current value
	mask = (1<<bitnumber);//create mask to shift value location
	if((value & mask)!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
	
}

void delay(volatile uint32_t dly)
{
	while(dly--);
}

void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber)
{
	Port->PUPDR = Port->PUPDR &~(3u << BitNumber*2); // clear pull-up resistor bits
	Port->PUPDR = Port->PUPDR | (1u << BitNumber*2); // set pull-up bit
}
