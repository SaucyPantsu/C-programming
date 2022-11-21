/*  

    Project : Assignment 2
    Author : Ryan McLoughlin C21431604
    Date Started: 10/11/21
    Purpose : A lottery game, using 1,3,5,7,9,11 as winning numbers. User is made to input their numbers before the full main menu can be accessed.

    functions made are as follows
    1) ArrayInput
    2) ArrayDisplay
    3) ArraySort
    4) ArrayCompare
    5) FrequencyCount
    6) DuplicateCheck
    
*/
//include Block

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function signatures

void ArrayInput(int *);
void ArrayDisplay(int *);
void ArraySort(int *);
void ArrayCompare(int *, int *, int *);
void FrequencyCount(int *, int *);
void DuplicateCheck(int *);


//symbolic name block
#define SIZE 6  //arraysize
#define LOTTOSIZE 42 //how big is the lotto

//beginning main
int main()
{
    //ints for controlling menu logic
    int NumSort = 0;
    int GamePlay = 0;
    int GameState = 0;
    //these are for the frequency mode, if lotto hasnt been played then frequency cannot be displayed
    int Plays = 0;
    int* PlayCheck = &Plays;
    //this array stores the user's lotto numbers
    int ArrayLotto[SIZE] = {0};
    //this array stores the frequency of the numbers selected
    int Freqency[LOTTOSIZE] = {0};

    //the game main menu
    do
    {
        //this ensures only 1->6 are available as menu options
        while (GameState <= 0 || GameState > 6)
        {
            //if the game hasnt been played yet, this if only allows 1 ad 6 to be choosen
            if (GamePlay == 0)
            {
                printf("Welcome to the Lotto!\n");
                printf("\nIf you would like to play, please press 1\n");
                printf("\nTo exit the game, Press 6\n");
                scanf("%d", &GameState);
                while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
                while(GameState != 1 && GameState != 6)
                {
                    printf("\nYou selected an invalid menu option, please try again\n");
                    scanf("%d", &GameState);
                }
                //this ensures that this menu option appears only once
                GamePlay = GamePlay++;
            }
            //if the game has been started, allow the whole menu choice to be seen
            else 
            {
                //the main menu
                printf("\n\nLotto Main Menu\n");
                printf("\nIf you would like to play, please press 1\n");
                printf("\nIf you wish to see your numbers, Press 2\n");
                printf("\nIf you would like to sort your numbers, Press 3\n");
                printf("\nIf you would like to see if you have won he Lotto, Press 4\n");
                printf("\nIf you wish to see the previous numbers you have chosen and their frequency, Press 5\n");
                printf("\nTo exit the game, Press 6\n");
                scanf("%d", &GameState);
                while(getchar() != '\n');//prevents infinite loop if wrong character if pressed

                if(GameState > 6 || GameState <1)
                {
                    printf("\nYou selected an invalid menu option, please try again\n");
                    scanf("%d", &GameState);
                    while(getchar() != '\n');//prevents infinite loop if wrong character if pressed

                }
            }
            //choose numbers menu option
            while(GameState == 1)
            {
                printf("\nYou have selected Number Selection Mode!\n");
                ArrayInput(ArrayLotto);
                GameState = 0;
                GamePlay = 1;
                NumSort = 0;
            }
            //view numbers menu option
            while(GameState == 2)
            {
                printf("\nYou have entered Number View Mode!\n");
                ArrayDisplay(ArrayLotto);
                GameState = 0;
                GamePlay = 1;
            }
            //number sort menu option
            while(GameState == 3)
            {
                printf("\nYou have entered Number Sort Mode!\n");
                ArraySort(ArrayLotto);
                GameState = 0;
                GamePlay = 1;
                NumSort = 1;
            }
            //lotto mode menu option
            while(GameState == 4)
            {
                //only allow the lotto to be played if the numbers have been sorted
                if(NumSort == 1)
                {
                    printf("\nLotto Mode! Feeling Lucky?\n");
                    ArrayCompare(ArrayLotto, Freqency, PlayCheck);
                    GameState = 0;
                    GamePlay = 1;
                }
                //if the numbers aren't sorted, inform the user to sort them
                else
                {
                    printf("\nYou have not sorted your numbers, Please select option 3 before you play!\n");
                    GameState = 0;
                }
            }
            //view number frequency mode
            while(GameState == 5)
            {
                printf("\nFrequency View Mode!\n");
                FrequencyCount(Freqency, PlayCheck);
                GameState = 0;
                GamePlay = 1; 
            }
        }
    } while (GameState !=6);
    //end game option 
    if (GameState == 6)
    {
        //ending message
        printf("\nThank you for playing the Lotto!\n\nPlease gamble responsibly!\n");
        //a graceful end
        return 0;
    }

}

//functions
void ArrayInput(int *LottoIn)//the input array
{
    //setting up loop control integers
    int j = 0;
    int i = 0;
    //start message
    printf("\nPlease choose 6 numbers between 1 and 42\n");
    //input loop
    for (i = 0; i < SIZE; i++)
    {
        printf("\nPlease Insert Number %d\n",i+1);
        scanf("%d",(LottoIn+i));
        while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
        while(*(LottoIn+i)<1 || *(LottoIn+i)>42)//ensuring inputs are in bounds
        {
            printf("\nError, the number is out of range 1-42, Try again\n");
            scanf("%d",(LottoIn+i));
            while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
        }

    }

    //the duplicate checker, based on a sorting algorithm, but if a duplicate is found it enforces a change to ensure there is no duplicate
    DuplicateCheck(LottoIn);
}

void DuplicateCheck(int *LottoIn)//checks the input array for duplicates
{
    //loop control ints
    int j = 0;
    int i = 0;
    //the duplicate checker, based on a sorting algorithm, but if a duplicate is found it enforces a change to ensure there is no duplicate
    for(i=0; i<SIZE-1; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            while(*(LottoIn+i) == *(LottoIn+j))
            {
                //this line gives a hint of where and what the duplicate is
                printf("\nYou have a duplicate number at position %d,(%d) Please insert a new number.\n", i+1,*(LottoIn+i));
                scanf("%d",(LottoIn+i));
                //if the duplicate is out of bounds, this while will catch it
                while(*(LottoIn+i)<1 || *(LottoIn+i)>42)
                {
                    printf("\nError, the number is out of range 1-42, Try again\n");
                    scanf("%d",(LottoIn+i));
                    while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
                }   
            }
        }   
    }
    //this loop is to make sure the user hasn't put in another duplicate number, it runs the Duplicate function again if it finds another duplicate
    for(i=0; i<SIZE-1; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(*(LottoIn+i) == *(LottoIn+j))
            {  
                DuplicateCheck(LottoIn);//recursion to ensure no sneaky duplicates occur
            }
        }   
    }
}

void ArrayDisplay(int *LottoIn)//prints the input array back to the user
{
    //array content display loop
    int i = 0;
    printf("\nYou have chosen: ");
    for (i = 0; i < SIZE; i++)
    {
        if(i != SIZE-1)//if array element is not the last element, print the number with a comma
        {
            printf("%d,", *(LottoIn+i));

        }
        else
        {
            printf("%d.\n", *(LottoIn+i));//if it is last element, full stop and skip to the next line
        }
    }
    
}

void ArraySort(int *LottoIn)//sort the user input
{
    //sort integer setup
    int i = 0;
    int j = 0;
    int temp = 0;

    //bubble sort loop
    for ( i = 0; i < SIZE - 1; i++)//go through each array element
    {
        for ( j = 0; j < SIZE-i-1; j++)//go through each array element
        {
            if(*(LottoIn+j)>*(LottoIn+(j+1)))// test each element to see if smaller or bigger than next one, if i+1 is bigger, swap
            {
                //number swap block
                temp = *(LottoIn+j);
                *(LottoIn+j) = *(LottoIn+(j+1));
                *(LottoIn+(j+1)) = temp;

            }
        } 
    }
}

void ArrayCompare(int *LottoIn, int *FrequencyCount, int *PlayCheck)//compare user input to winning numbers
{
    *PlayCheck = 1;
    int i = 0;
    int j = 0;
    int temp = 0;
    int WinningArray[SIZE] = {1,3,5,7,9,11};
    int MatchCount = 0;
    /*
    N.B 
        ****!!!!frequencycount element 0 == Number 1, ie number the user puts in is i+1, as the first element is always 0!!!!****
                Do not forget this when setting up the printf


                this counts the frequency of numbers the user has put in, my code only counts the number frequency if the game is played, 
                this is based on my understanding of the program brief

    */
    
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<LOTTOSIZE; j++)
        {
            if(*(LottoIn+i) == (j+1))//if number selected as lucky numbers comes up, and matches j+1
            {
                temp = *(FrequencyCount+j);//increment element j by 1
                temp = temp +1;
                (*(FrequencyCount+j)) = temp;
            }
        }
    }
    /*
    //printing the winnng array
    for(i=0; i<SIZE; i++)
    {
        printf("\nWinning number %d is %d", i+1, WinningArray[i]);
    }
    */
    //just addinf some space between winnng numbers and the prize block
    printf("\n\n");
    //compare user input to winning array
    for(i=0; i<SIZE; i++)//sort loop
    {
        for(j=0; j<SIZE; j++)
        { 
            if(*(LottoIn+i) == WinningArray[j])//if number matches winning number, the match count counter increments by 1
            {
                MatchCount = MatchCount+1;    
            }
        }
    }
    // if matchcount matches 3,4,5||6, it activates appropriate if statement,otherwise it fails
    if(MatchCount == 3)
    {
        printf("\nYou matched 3 numbers, you win a Cinema pass!\n");
    }
    if(MatchCount == 4)
    {
        printf("\nYou matched 4 numbers, you win a Weekend Away!\n");
    }
    if(MatchCount == 5)
    {
        printf("\nYou matched 5 numbers, you win a New Car!\n");
    }
    if(MatchCount == 6)
    {
        printf("\nYou matched 6 numbers, you win the Jackpot!\n");
    }
    if(MatchCount > 6)//if some strange error occurs and matchcount is larger than 6, this error occurs
    {
        printf("\nTerminal Error, please try again.\n");
    }
    if(MatchCount < 3)//if you lse this activates
    {
        printf("\nA pity, you haven't matched enough to win a prize, try again!\n");
    }
}

void FrequencyCount(int *FrequencyCount, int *PlayCheck)//displays number selection frequency
{
    printf("\nYou have entered Frequency Mode!\n");
    int i = 0;
    //if lotto has been played, display frequency
    if (*(PlayCheck) == 1)
    {
        for(i=0; i<LOTTOSIZE; i++)
        {
            if (*(FrequencyCount+i) != 0)
            {
                printf("\nNumber %d has been selected %d times.\n",i+1, *(FrequencyCount+i));
            }
        }
    }
    //if lotto has not been played, return this error
    else
    {
        printf("\n\nYou have not yet played the game, so there is no number frequency to display!");
    }
}