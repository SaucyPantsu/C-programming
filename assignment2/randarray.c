#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void InsertSort(int *);
void Merge(int *, int *, int *);

int main()
{
    int i = 0;
    int ArrayA[SIZE] = {0};
    int ArrayB[SIZE] = {0};
    int BigArray[SIZE*2] = {0};

    srand(time(0));
    for(i = 0; i<SIZE; i++)
    {
        ArrayA[i] = rand()%100;
    }
    for(i = 0; i<SIZE; i++)
    {
        ArrayB[i] = rand()%100;
    }

    InsertSort(ArrayA);
    InsertSort(ArrayB);
    Merge(ArrayA, ArrayB, BigArray);

    for(i = 0; i<(SIZE*2); i++)
    {
        printf("\n%d", BigArray[i]);
    }

    return 0;
}
void InsertSort(int *ArrayIn)
{

    int i = 0;
    int j = 0;
    int current = 0;

    for(i = 1; i < SIZE; i++)
    {
        current = *(ArrayIn+i);
        j = i-1;
        while(current < *(ArrayIn+j) && j >= 0)
        {
            *(ArrayIn+(j+1)) = *ArrayIn+j;
            --j; 
        }
        *(ArrayIn+(j+1)) = current;
    }
}

void Merge(int *ArrayA, int *ArrayB, int *BigArray)
{
    int i = 0;
    for(i = 0; i<(SIZE*2); i+2)
    {
        if (*(ArrayA + i)<*(ArrayB+i))
        {
            *(BigArray+i) = *(ArrayA + i);
            *(BigArray+(i+1)) = *(ArrayB + i);
        }
        
        else if (*(ArrayA + i)>*(ArrayB+i))
        {
            *(BigArray+i) = *(ArrayB + i);
            *(BigArray+(i+1)) = *(ArrayA + i);
        }
    }
}