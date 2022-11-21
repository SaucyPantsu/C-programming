#include<math.h>
#include<stdio.h>

int main()
{
    //variables needed
    int initialInput = 0;
    int iterations = 0;
    int result = 0;
    int memory = 0;

    //inputs
    printf("Please insert an integer to see if prime\n");
    scanf("%d", &initialInput);

    result = initialInput%2;

    while (iterations<initialInput)
    {


        iterations=iterations++;
        result = initialInput%iterations;
        memory = memory + result;
        
    }
    

return 0;
}