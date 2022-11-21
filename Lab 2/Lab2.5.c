#include <stdio.h>

//Program to determine circle area
    int main()
        {
            //Variables
            int a;
            int b;
            int c;
            int d;
            int e;

            float aResult;
            float bResult;
            float cResult;
            float dResult;
            float eResult;
            float eResult2;

            a = 2;
            b = 3;
            c = 5;
            d = 7;
            e = 100;

            //calculations

            aResult = a % 2;
            bResult = b % 2;
            cResult = c % 2;
            dResult = d % 3;
            eResult = e % 33;
            eResult2 = e % 7;

            //Outputs
            
            printf("A is %f\nB is %f\nC is %f\nD is %f\nE is %f\nF is %f\n",aResult,bResult,cResult,dResult,eResult,eResult2);

            return(0);


        }