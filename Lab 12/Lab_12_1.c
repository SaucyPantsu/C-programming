//headers
#include <stdio.h>

//function signatures

void startime(void);

//symbolic name block
#define STARS 10

//beginning main
int main()
{

    startime();//run startime function
    return(0);
}
//startime function
void startime(void)
{
    int i = 0;

    while(i<STARS)//print STARS number of stars
    {
        printf("*");
        i = i+1;
    }
    printf("\n\n");//empty space to prevent console getting cluttered
}