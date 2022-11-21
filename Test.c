#include<stdio.h>



void main()
{

   int a;
   int b;
   int c;

   a = 1;
   b = 3;
   c = 0;

   printf("A = %d, B = %d, Placeholder = %d\n",a,b,c);

   c = a;
   a = b;
   b = c;

   printf("A = %d, B = %d, Placeholder = %d\n",a,b,c);


}
