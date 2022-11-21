#include <stdio.h>

//Program to determine circle area
    int main()
        {
            //Variable declaration

            float pi;
            float radius;
            float area;
            pi = 3.14;
            radius = 4.8;
            area = 0;

            //Calculation for area
            //pi*r*r
            area = pi*radius*radius;

            //Output

            printf("The area is %fcm^2",area);
        }