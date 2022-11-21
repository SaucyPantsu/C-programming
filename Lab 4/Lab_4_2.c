#include<math.h>
#include<stdio.h>

int main()
{
    //variables needed
    float initialInput = 0;
    float tempNumber = 0;
    float result = 0;
    int iterations = 0;

    //inputs
    printf("Please insert an integer greater than 0\n");
    scanf("%f", &initialInput);

    if (initialInput < 0)
    {
        printf("Error, number less than 0");
        return 0;
    }

    //while the value of the initial variable is greater thatn 1
    while (initialInput !=1.0)
    {
        tempNumber = remainder(initialInput,2);
        if (tempNumber == 0)
        {
            initialInput = initialInput/2;
            printf("The Current value is %0.1f\n", initialInput);
            iterations = iterations+1;
        }
        else
        {
            initialInput = (initialInput*3) + 1;
            printf("The Current value is %0.1f\n", initialInput);
            iterations = iterations+1;
        }

    }
    //final output
    printf("The final value is %0.1f, with %d iterations\n", initialInput, iterations);


    return 0;
}
//end of main