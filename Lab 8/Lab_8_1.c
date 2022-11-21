/*  

    Project : 2D arrays
    Author : Ryan McLoughlin C21431604
    Date Started: 22/11/21
    Purpose : Arrays

*/

//include
#include <stdio.h>
//symbolics
#define ROW 3
#define COLUMN 4
//beginning main
int main()
{
    int Array_1 [ROW][COLUMN] = {1,2,3,4,
                                 4,3,2,1,
                                 2,1,3,4};

    int Array_2 [ROW][COLUMN] = {5,6,7,8,
                                 8,7,6,5,
                                 5,8,6,7};

    int Array_3 [ROW][COLUMN] = {0};

    int i = 0;
    int j = 0;


    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COLUMN; j++)
        {
            Array_3[i][j] = Array_1[i][j] * Array_2[i][j];
            printf("%d,", Array_3[i][j]);
        }
    }

}//End Main