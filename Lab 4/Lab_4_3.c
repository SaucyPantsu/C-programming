#include<math.h>
#include<stdio.h>

int main()
{
    //variables needed
    int initialInput = 0;
    int iterations = 0;
    int result = 0;

    //inputs
    printf("Please insert an integer greater than 0 and less than 5\n");
    scanf("%d", &initialInput);

    //startwhile

    while (iterations<20)
    {
        iterations = iterations+1;
        
        result = iterations%initialInput;

        //startif

        if (result == 0)
        {
            printf("%d is divisible by %d\n",iterations,initialInput);
        }
        //endif
    }
    //endwhile

   

    return 0;
}
//end of main