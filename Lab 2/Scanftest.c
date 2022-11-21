#include <stdio.h>
#include <direct.h>

//Program to determine Cube Volume
    int main()
        {
            //Variable declatation

            float Length;
            float Volume;
            Length = 0;

            printf("Please Insert a Length\n");
            scanf("%f", &Length);
            // Volume = length^3

            Volume = Length*Length*Length;

            //Output

            printf("The Volume is %fm^3\n",Volume);
            
            return(0);
        }