/*
    lab test 2
    Author : Ryan McLoughlin C21431604
    Purpose : Currency Conversion
    Date : 24/2/22
*/

//include block
#include <stdio.h>
#include <stdlib.h>

//definitions
#define EUROAMOUNT 3
#define DOLLARAMOUNT 3

//function signatures
float Change_To_Dollar(float *);
float Change_To_Euro(float *);

//main
int main()
{
    //variable block
    int ProgramState = 0;
    float EuroArray[EUROAMOUNT];
    float DollarArray[DOLLARAMOUNT];
    int i = 0;
    float euroTotal;
    float dollarTotal;

    if(ProgramState>3 || ProgramState < 1)
        {
            //program introduction
            printf("Which program mode do you wish to enter?\n\n1)Euro\n2)Dollar\n3)Exit Program\n\n");
            //setting state
            scanf("%d", &ProgramState);
        }

    //if euro mode is selected
    while(ProgramState == 1)
    {
        //introduce mode
        printf("\nYou have entered Euro mode!\n");

        //input data
        for(i=0; i<EUROAMOUNT; i++)
        {
            printf("\nPlease enter Euro amount %d\n", i+1);
            scanf("%f", & EuroArray[i]);
        }

        euroTotal = Change_To_Dollar(&EuroArray);

        printf("\n\nYour average total converted to dollar is %f\n\n", euroTotal);


        printf("Which program mode do you wish to enter?\n\n1)Euro\n2)Dollar\n3)Exit Program\n\n");
        //setting state
        scanf("%d", &ProgramState);



    }

    //if dollar mode is selected
    while (ProgramState == 2)
    {
        //introduce mode
        printf("\nYou have entered Dollar mode!\n");

        //input data
        for(i=0; i<DOLLARAMOUNT; i++)
        {
            printf("\nPlease enter Dollar amount %d\n", i+1);
            scanf("%f", & DollarArray[i]);
        }

        dollarTotal = Change_To_Euro(&DollarArray);

        printf("\n\nYour average total converted to Euro is %f\n\n", dollarTotal);

        printf("Which program mode do you wish to enter?\n\n1)Euro\n2)Dollar\n3)Exit Program\n\n");
        //setting state
        scanf("%d", &ProgramState);


    }

    //exit state
    while (ProgramState == 3)
    {
        printf("Thank you for running my program!");
        return 0;
    }



    return 0;
}

//function code

float Change_To_Dollar(float EuroIn[])
{

    float total;
    int i = 0;
    //confirming input
    printf("You have entered:\n");
    for(i=0; i< EUROAMOUNT; i++)
    {
        printf("Eur %f\n", EuroIn[i]);
    }

    //calculating total

    for(i=0; i<EUROAMOUNT; i++)
    {
        total = total + (EuroIn[i]);

    }
    //converting total
    total = total * 1.1;

    //averaging total
    total = total/EUROAMOUNT;


    //returning total
    return total;
        



}
float Change_To_Euro(float DollarIn[])
{
    float total;
    int i = 0;

    //confirming total
    printf("You have entered:\n");
    for(i=0; i< DOLLARAMOUNT; i++)
    {
        printf("$ %f\n", DollarIn[i]);
    }

    //calculating total
    for(i=0; i<DOLLARAMOUNT; i++)
    {
        total = total + (DollarIn[i]);

    }
    //converting total
    total = total * 0.9;
    //averaging total
    total = total/DOLLARAMOUNT;
    //returning total
    return total;
        

}

