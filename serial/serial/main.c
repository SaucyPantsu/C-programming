#include <stm32f031x6.h>

void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);
void delay(volatile uint32_t dly);
void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber);
void eputchar(char c);
char egetchar(void);
void eputs(char *String);
void printDecimal(int32_t Value);
void SerialBegin(void);
void initClock(void);
void printHex(int32_t Value);

int main()
{
	int32_t count = -10;
	initClock();
	SerialBegin();
	while(1)
	{
		printHex(count++); //print count in hex
		eputs("\r\n");
		delay(1000000);
	}

	return 0;
}
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode)
{
	// This function writes the given Mode bits to the appropriate location for
	// the given BitNumber in the Port specified.  It leaves other bits unchanged
	// Mode values:
	// 0 : digital input
	// 1 : digital output
	// 2 : Alternative function
	// 3 : Analog input
	uint32_t mode_value = Port->MODER; // read current value of Mode register 
	Mode = Mode << (2 * BitNumber);    // There are two Mode bits per port bit so need to shift
																	   // the mask for Mode up to the proper location
	mode_value = mode_value & ~(3u << (BitNumber * 2)); // Clear out old mode bits
	mode_value = mode_value | Mode; // set new bits
	Port->MODER = mode_value; // write back to port mode register
}
void delay(volatile uint32_t dly)
{
	while(dly--);
}
void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber)
{
		Port->PUPDR = Port->PUPDR & ~(3u << BitNumber*2); // clear pull-up bits
		Port->PUPDR = Port->PUPDR | (1u << BitNumber*2); //  set pull-up bit
}

void SerialBegin()
{
	/* On the nucleo board, TX is on PA2 while RX is on PA15 */
	RCC->AHBENR |= (1 << 17); // enable GPIOA
	RCC->APB2ENR |= (1 << 14); // enable USART1
	pinMode(GPIOA,2,2); // enable alternate function on PA2
	pinMode(GPIOA,15,2); // enable alternate function on PA15
	// AF1 = USART1 TX on PA2
	GPIOA->AFR[0] &= 0xfffff0ff;
	GPIOA->AFR[0] |= (1 << 8);
	// AF1 = USART1 RX on PA2
	GPIOA->AFR[1] &= 0x0fffffff;
	GPIOA->AFR[1] |= (1 << 28);
	// De-assert reset of USART1 
	RCC->APB2RSTR &= ~(1u << 14);
	
	USART1->CR1 = 0; // disable before configuration
	USART1->CR3 |= (1 << 12); // disable overrun detection
	USART1->BRR = 48000000/9600; // assuming 48MHz clock and 9600 bps data rate
	USART1->CR1 |= (1 << 2) + (1 << 3); // enable Transmistter and receiver
	USART1->CR1 |= 1; // enable the UART

}
void eputchar(char c)
{
	while( (USART1->ISR & (1 << 6)) == 0); // wait for any ongoing
	USART1->ICR=0xffffffff;
	// transmission to finish
	USART1->TDR = c;
}
char egetchar()
{
	while( (USART1->ISR & (1 << 5)) == 0); // wait for a character
	return (char)USART1->RDR;
}
void eputs(char *String)
{
	while(*String) // keep printing until a NULL is found
	{
		eputchar(*String);
		String++;
	}
}
void printDecimal(int32_t Value)
{
	
	char DecimalString[12]; // a 32 bit value range from -2 billion to +2 billion approx
												// That's 10 digits
												// plus a null character, plus a sign
	DecimalString[11] = 0; // terminate the string;
	if (Value < 0)
	{
		eputchar(' -'); //tabbing in the numbers by a space to keep tidy
		Value = -Value;
	}
		
	else
	{
		eputchar(' '); //removing + sign
	}
	int index = 10;
	while(index > 0)
	{
		DecimalString[index]=(Value % 10) + '0'; //converting to decimal
		Value = Value/10;
		
		if(Value == 0) // remove leading 0s
		{
			break;
		}
		
		index--;	
	}
	eputs(&DecimalString[index]);//outputting decimal
}

void printHex(int32_t Value)
{
	char HexString[9]; // array length 10 to include 8 hex bits and null character
	HexString[8] = '\0'; // set final bit to be null character
	int index = 8;
	if (Value < 0)
	{
		eputchar('-');
		Value = -Value;
	}
	
	while(index > 0)
	{
		if(Value % 16 > 9) // check if the number modulus is greater than 9
		{
			HexString[index] = (Value % 16) + '7'; //if so, offset by 7 to hit correc ascii
		}
		else
		{
			HexString[index] = (Value % 16) + '0'; // else leave alone
		}
		
		Value = Value/16;
		index--; //increment index
	}
	
 
    // display integer into character
   eputs(&HexString[index]);
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

// Do the following to push HSI clock out on PA8 (MCO)
// for measurement purposes.  Should be 8MHz or thereabouts (verified with oscilloscope)
/*
        RCC_CFGR |= ( (1<<26) | (1<<24) );
        RCC_AHBENR |= (1<<17);
        GPIOA_MODER |= (1<<17);
*/
        // and turn the PLL back on again
        RCC->CR |= (1<<24);        
        // set PLL as system clock source 
        RCC->CFGR |= (1<<1);
}

