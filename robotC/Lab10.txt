#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 20


int main()
{
    int j = 0;
    int i = 0;
    char Input[SIZE];

    fgets(Input,(SIZE-1), stdin);
    
    for(i=0; i<SIZE; i++)
    {
        if(Input[i] == '*')
        {
            j = i;
            for(j = i=1; j<SIZE; j++)
            {
                if(Input[j] != '*')
                {
                    Input[j] = Input[j] - 32;
                }
                else
                {
                    break;
                }

            }
        }

    }
    for(i=0; i<SIZE;i++)
    {
        printf("%c", Input[i]);
    }
}