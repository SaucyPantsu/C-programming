#include <stdio.h>

//symbolic name block
#define SIZE 4 //reset value

//beginning main
int main()
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int ArrayA[SIZE]= {0};
    int counter = 0;
    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &ArrayA[i]);

    }
    printf("\nInput Complete\n");


    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
        {   
            counter = counter+1;
            if(ArrayA[j] > ArrayA[j+1])
            {
                temp = ArrayA[j];
                ArrayA[j]= ArrayA[j+1];
                ArrayA[j+1] = temp;
            }
            

        } 
    }

    for( i = 0; i < SIZE; i++)
    {
        printf("\n%d,", ArrayA[i]);
    }
    printf("\nCount is %d",counter);
    return 0;
}