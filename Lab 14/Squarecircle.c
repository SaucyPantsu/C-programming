//includes
#include <stdio.h>

//definitons


//funcion signatures

float square(float *);
float circle(float *);


//code
int main()
{
    //variables
    float squareSide = 0;
    float circleRadius = 0;
    float squareSize = 0;
    float circleSize = 0;
    
    //input block
    printf("What is the length of a side of your square?\n");
    scanf("%f", &squareSide);

    printf("What is the length of the radius of your circle?\n");
    scanf("%f", &circleRadius);

    //calculation block
    squareSize = square(&squareSide);
    circleSize = circle(&circleRadius);

    //output block
    printf("\nThe square is %f cm^2\n",squareSize );
    printf("\nThe circle is %f cm^2\n",circleSize );
    printf("\a");
}

//square area calculations
float square(float *side)
{
    float area = (*side)*(*side);
    return area;
}

//circle area calculations
float circle(float *radius)
{
    float Carea = (3.14)*(*radius)*(*radius);
    return Carea;
}