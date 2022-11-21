#include<stdio.h>
//a program that takes input numbers and displays it back

int main()
{

    //variables
    float celsius;
    float fahren;
    
    celsius = 0;
    fahren = 0;

    printf("Enter a temperature in Celsius\n");
    scanf("%f", &celsius);
    //calculations
    fahren = (celsius*(9/5) + 32);

    //outputs
    printf("The temperature is %fF\n",fahren);
    return 0;
    
}




