#include<math.h>
#include<stdio.h>

int main()
{
    //variables needed
    int iterations = 0;
    int result = 0;


    //startwhile

    while (iterations<100)
    {
        iterations = iterations+1;
        
        result = iterations%2;

        //startif
        if (iterations ==100)
        {
            printf("%d", iterations);
        }
        else if (result == 0)
        {
            printf("%d,",iterations);
        }

        //endif
    }
    //endwhile

   

    return 0;
}
//end of main