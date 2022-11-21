/*  

    Project : Template
    Author : Ryan McLoughlin C21431604
    Date Started: 
    Purpose : 

*/

//include
#include <stdio.h>

#define ROW 3
#define COLUMN 2

//beginning main
int main()
{
    int data_array[ROW][COLUMN];
    int Biggest = data_array[0][0];
    int Smallest = data_array[0][0];
    int i = 0;
    int j = 0;
    float average = 0;
    int total = 0;

    data_array[0][0] = 0,0;


    //read loop
    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COLUMN; j++)
        {
            scanf("\n%d\n", &data_array[i][j]);
        }
    }

    i = 0;
    j = 0;

    //print loop
    printf("\n\n");

    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COLUMN; j++)
        {
            printf("%d,", data_array[i][j]);
        }
    }

    //Lowest/highest Number
    i = 0;
    j = 0;

    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COLUMN; j++)
        {
            if(Biggest < data_array[i][j])
            {
                Biggest = data_array[i][j];
            }

            if(Smallest > data_array[i][j])
            {
                Smallest = data_array[i][j];
            }
        }
    }
    printf("\n\n%d is largest, %d is smallest", Biggest, Smallest);

    //average
    i = 0;
    j = 0;

    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COLUMN; j++)
        {
            total = total + data_array[i][j];
        }
    }
    average = (float)(total)/(ROW*COLUMN);
    printf("\n\n%d is the total\n\n", total);
    printf("\n\n%0.1f is the average\n\n", average);

    return 0;

}//End Main