#include<stdio.h>
//a program that takes input numbers and displays it back

int main()
{

    //declaring variables
    char input1 = 0;
    char input2 = 0;

    //scan statements
    printf("Please insert character 1\n");
    scanf("%c", &input1);
    while (getchar() != '\n');


    printf("Please insert character 2\n");
    scanf("%c", &input2);
    
    //output statement
    
    printf("The characters are %c, %c\n", input1,input2);
    

    return 0;
}
