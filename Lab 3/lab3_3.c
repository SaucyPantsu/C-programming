#include<stdio.h>

//a program that takes input numbers and displays it back

int main()
{

    //declaring variables
    float input1 = 0;
    float input2 = 0;
    float input3 = 0;

    //scan statements
    printf("Please insert number 1\n");
    scanf("%f", &input1);
    while (getchar() != '\n');
    printf("Please insert number 2\n");
    scanf("%f", &input2);
    printf("Please insert number 3\n");
    scanf("%f", &input3);

    //output statement

    printf("The numbers are %.4f, %.3f, %.0f\n", input1,input2,input3);
    

    return 0;
}
