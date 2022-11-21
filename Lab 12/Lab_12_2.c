//headers
#include <stdio.h>

//function signatures

int startime(char, int);

//symbolic name block
#define STARS 10

//beginning main
int main()
{
    int numberOfChar = 0;
    char DesiredChar;
    printf("what character would you like?\n\n");
    scanf("%c", &DesiredChar);
    printf("How many would you like?\n\n");
    scanf("%d",&numberOfChar);
    startime(DesiredChar,numberOfChar);//run startime function
    return(0);
}
//startime function
int startime(char DesiredChar, int numberOfChar)
{
    int i = 0;

    while(i<numberOfChar)//print STARS number of stars
    {
        printf("%c", DesiredChar);
        i = i+1;
    }
    printf("\n\n");//empty space to prevent console getting cluttered
    return(0);
}