#include<stdio.h>

//a program that takes input numbers and displays it back

int main()
{

    //declaring variables
    int input1 = 0;
    int input2 = 0;
    int input3 = 0;

    //scan statements
    printf("Please insert number 1\n");
    scanf("%d", &input1);
    printf("Please insert number 2\n");
    scanf("%d", &input2);
    printf("Please insert number 3\n");
    scanf("%d", &input3);

    //output statements

    printf("The numbers are %d, %d, %d\n", input1,input2,input3);
    

    return 0;
}
