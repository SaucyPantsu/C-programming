#include <stdio.h>

//Program to determine box sizes
    int main()
        {
            //variable declarations
            float length;
            float width;
            float height;
            float SurfaceArea;
            float Volume;

            length = 11.5;
            width = 2.5;
            height = 10.0;
            SurfaceArea = 0;
            Volume = 0;

            //calculations for SA
            
            SurfaceArea = 2*(length*width) + 2*(width*height) + 2*(height*length);
            
            //Calculation for Area

            Volume = length*width*height;

            //outputs

            printf("Volume is %fcm^3\n",Volume);
            printf("Surfacw area is %fcm^2\n",SurfaceArea);
            
        }