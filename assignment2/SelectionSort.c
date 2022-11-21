#include <stdio.h>

//symbolic name block
#define SIZE 4 //reset value

//beginning main
int main()
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int max =0;
    int min = 0;

    int ArrayA[SIZE]= {0};
    int counter = 0;

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &ArrayA[i]);

    }

    for (i = 0; i < SIZE; i++)
    {
        counter = counter +1;
        min = i;
        for (j = i+1; j < SIZE; j++)
        {
            if(ArrayA[j] < ArrayA[min])
            min = j;
        }
        temp = ArrayA[min];
        ArrayA[min] = ArrayA[i];
        ArrayA[i] = temp;
    }
    
    printf("\nInput Complete\n");
    for( i = 0; i < SIZE; i++)
    {
        printf("\n%d,", ArrayA[i]);
    }
    printf("\nCount is %d",counter);
    return 0;
}