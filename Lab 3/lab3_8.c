#include<stdio.h>
//a program that takes input numbers and displays it back

int main()
{
    //variables
    float Number1;
    float Number2;
    float Number3;

    float sum;
    float average;

    //input scans
    printf("Please insert a number\n");
    scanf("%f", &Number1);
    while (getchar() != '\n');
    printf("And another\n");
    scanf("%f", &Number2);
    printf("And another\n");
    scanf("%f", &Number3);

    //calculations

    sum = Number1 + Number2 + Number3;
    average = sum/3;

    //output statement

    printf("The sum is %f, and the average is %f", sum, average);


    

}


