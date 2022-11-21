#include <stdio.h>
#include <math.h>

int main()
    {
        float loopy;
        float loopy2;
        float output;
        float memory;
        output = 0;
        loopy = 1;
        loopy2 = 0;
        memory = 0;

        while (loopy <= 2.0 )
        {
           memory = loopy + (memory + 0.1);
           loopy = loopy + 0.1;
           loopy2 = loopy2 + 1;
        }
        output = (memory+1)/loopy2;
        printf("%f,%f,%f,%f", output, loopy, loopy2,memory);
    }