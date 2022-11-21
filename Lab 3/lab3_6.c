#include<stdio.h>
//a program that takes input numbers and displays it back

int main()
{
    //variables
    float celsius;
    float fahren;
    
    celsius = 0;
    fahren = 0;
    //input data
    printf("Enter a temperature in Fahrenheit\n");
    scanf("%f", &fahren);

    //calculations
    celsius = ((fahren - 32.0)*(5.0/9.0));
    
    //outputs
    printf("The temperature is %fC\n",celsius);

    return 0;
}