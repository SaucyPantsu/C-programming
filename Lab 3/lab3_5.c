#include<stdio.h>
//a program that takes input numbers and displays it back

int main()
{

    //declaring variables
    int years  = 0;
    int avgheart = 75;
    int heartbeats = 0;
    int minutes = 0;

    //input
    printf("Please insert Age in years\n");
    scanf("%d", &years);
    while (getchar() != '\n');

    //calculations
    minutes = ((years*365)*(60))*(60);
    heartbeats = minutes*avgheart;


    //outputs
    printf("At the age of %d, you have had your heart beat %d times", years, heartbeats);
    

    return 0;
}