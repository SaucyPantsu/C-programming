#include <stdio.h>

//symbolic name block
#define SIZE 5 //reset value

//beginning main
int main()
{
    int i = 0;
    int j = 0;
    int ArrayA[SIZE]= {0};
    int current = 0;

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &ArrayA[i]);

    }
    printf("\nInput Complete\n");

    for(i = 0; i < SIZE; i++)
    {
        if(i < 0)
        {    
            current = ArrayA[i-1];
            j = i-1;
            while(ArrayA[j-1] > current)
            {
                ArrayA[j] = ArrayA[j-1];
                j = j-1;
            }
            ArrayA[j] = current;
        }
        else
        {
            current = ArrayA[i];
            j = i;
            while(ArrayA[j] > current)
            {
                ArrayA[j] = ArrayA[j];
                j = j;
            }
            ArrayA[j] = current;

        }
    }
    printf("\nSort Complete\n");
    
    for( i = 0; i < SIZE; i++)
    {
        printf("\n%d,", ArrayA[i]);
    }
    return 0;
    
}