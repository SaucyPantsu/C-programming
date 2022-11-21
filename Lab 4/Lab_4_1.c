#include<stdio.h>
//listing numbers from ten to one
int main()
{
    //variable to start with
    int number = 10;
    while (number != 0)
    {
        //checking if the number is going to be the last one
        if (number>1)
        {
            printf("%d,",number);
            number = number-1; //very important, actually lets the loop eventually end
        }
        else
        {
            //last number in the loop
            printf("%d",number);
            number = number-1;
        }

    }

    return 0;
}
//end of main
