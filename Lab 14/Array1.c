//includes
#include <stdio.h>

//definitons
#define SIZE 5

//funcion signatures

int largest(int *);


//code
int main()
{
    int input[SIZE];
    int i = 0;

    for(i=0; i < SIZE; i++)
    {
        printf("Please insert number %d\n", (i + 1));
        scanf("%d", &input[i]);
    }

    int biggest = largest(input);

    printf("%d is biggest\n", biggest);

}

int largest(int *sort_array) 
{
    int big = *sort_array;
    int i = 0;
    for(i=0; i < SIZE; i++)
    {
        if (big < *(sort_array + i))
        {
            big = *(sort_array + i);
        }


    }
    return big;


}
