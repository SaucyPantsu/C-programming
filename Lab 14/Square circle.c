//includes
#include <stdio.h>

//definitons


//funcion signatures

float square(float);
float circle(float);


//code
int main()
{

    float squareSide = 0;
    float circleRadius = 0;
    float squareSize = 0;
    float circleSize = 0;

    printf("What is the length of a side of your square?")
    scanf("%f", &squareSide);

    printf("What is the length of the radius of your circle?")
    scanf("%f", &circleRadius);

    squareSize = Square(squareSide);
    circleSize = Circle(circleRadius);
    printf("The square is %f cm^2",squareSize );
    printf("The circle is %f cm^2",circleSize );
}

float square(float side)
{
    float area = side*side;

    return area;

}

float circle(float radius)
{
    float Carea = ((3.14)*radius)^2;
    return Carea;


}