#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main()
{
    int i = 0;
    int Array[SIZE] = {1,2,3,4,5};
    int Big = Array[0];
    int Small = Array[0];
    
    for(i = 0; i<SIZE; i++)
    {
        if(Array[i]> Big)
        {
            Big = Array[i];
        }
        if(Array[i]< Small)
        {
            Small = Array[i];
        }

    }
    printf("\n\n%d is big, and %d is small", Big, Small);

    return 0;
}