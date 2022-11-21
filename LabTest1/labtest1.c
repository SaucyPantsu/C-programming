/*  

    Lab Test Number 1
    Author : Ryan McLoughlin C21431604
    Date : 8/11/21
    Purpose : Fibonacci Series

*/

#include <stdio.h>


//beginning main
int main()
{
    //variable block
    int total = 1;
    int prevTotal = 0;
    int fibonacci = 0;
    int iteration = 0;
    int userIn = 0;
    int EndCondit = 1;

    //introduction print
    printf("Fibonacci Term Generator\n");
    printf("To run the program, enter 1\nTo end the program, enter 0\n");
    scanf("%d", &EndCondit);

    if (EndCondit != 0 && EndCondit != 1)
    {
        printf("Seems you have made an error, please try again\n");
        scanf("%d", &EndCondit);
    }
    
    //Want To Run program while
    while(EndCondit == 1)
        {
            //input for number in sequence
            printf("Please insert a number of terms you wish to see\n");

                //resetting values incase program has already run
                userIn = 0;
                total = 1;
                prevTotal = 0;
                fibonacci = 0;
                iteration = 0;  

                scanf("%d", &userIn);
                userIn = userIn - 2;
                //error checking for values that would give a give a negative int
                //if user inputs 0
                    if (userIn == -2)
                        {
                            printf("Error, Please insert a number greater than 0");

                        }//end if
                //if user inputs 1
                    else if (userIn == -1)
                        {
                            printf("0");
                        }//end else if
                //if user inputs 2
                    else if (userIn == 0)
                        {
                            printf("0,1");
                        }//end else if
                //if user puts in any number over 2    
                    else //start else
                        {
                            printf("0,1,");
                            //fibonacci loop
                            while(iteration<userIn)
                                {   
                                    fibonacci = prevTotal + total;
                                    prevTotal = total;
                                    total = fibonacci;
                                    iteration = iteration + 1;
                                    printf("%d,", fibonacci);
                                }//end while
                        }//end else

                        //to repeat code
                        printf("\n\nFibonacci Term Generator\n");
                        printf("To run the program, enter 1\nTo end the program, enter 0\n");
                        scanf("%d", &EndCondit);
        }
        //end while
    //ending program
    printf("Thank you for running my program!");
    return 0;
}
//end main