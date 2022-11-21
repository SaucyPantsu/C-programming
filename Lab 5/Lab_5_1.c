/*  

    Project : Assignment 1
    Author : Ryan McLoughlin C21431604
    Date Started: 10/11/21
    Purpose : Maths Quiz game

*/

//include
#include <stdio.h>

//beginning main
int main()


{
    int i = 0;
    int a[10];

    for (i = 0; i < 10; i++)
    {
        a[i] = 9 -i;
        
    }

    for (i = 0; i < 10; i++)
    {
        a[i] = a[ a[i] ];
    }


    printf("\n\n%d\n\n", a[8]);


}//End Main