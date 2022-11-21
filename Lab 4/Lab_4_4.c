#include<math.h>
#include<stdio.h>

int main()
{
    //variables needed
    int initialInput = 0;
    int iterations = 0;
    int result = 0;

    //while statement
    while(iterations<10)
    {
        //iterations for counting
        iterations = iterations + 1;
        printf("%d\n", iterations);
        //testing for 3 or 7
        if(iterations == 3 || iterations == 7)
        {
            printf("We are at %d\n", iterations);
        }


    }

    return 0;
}
//end of main