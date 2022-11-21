#include <stdio.h>
#include <math.h>

main()
    {
        int loopy;
        loopy = 0;

        while (loopy < 5)
        {
           loopy = ++loopy;
        }

        printf("%d", loopy);
    }