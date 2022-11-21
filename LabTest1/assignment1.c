/*  

    Project : Assignment 1
    Author : Ryan McLoughlin C21431604
    Date Started: 10/11/21
    Purpose : Maths Quiz game

*/
//include

#include <stdio.h>

//symbolic name block
#define RESET 0 //reset value

//beginning main
int main()
{

    //integer reset and initialisation
    int GameState = RESET;
    int WinCounter = RESET;
    int LossCounter = RESET;
    int QuestionAmount = RESET;
    int QuizLoop = RESET;
    int Answers = RESET;
    int UserIn = RESET;
    int GamePlay = RESET;
    int QuestionSetState = RESET;

    /*  
        GameState State Labels
        1 is set number of questions
        2 is play the game
        3 is to see your last score
        4 is to end the game
    */

    //initial input 
    while (GameState !=4)
    {   

        //errorchecking for invalid menu selection
        while (GameState <= 0 || GameState > 4)
        {   
            
            

            if (GamePlay == 0)
            {   //counter to see if game has already been played
                printf("\n\nRyan's Maths Game\n");
                printf("\nTo set your amount of questions, enter 1\nTo play the game, enter 2\nTo end the program, enter 4\n\n");
                scanf("%d", &GameState);
                while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
            }

            else
            {   //if game has been played, makes score page visible
                printf("\n\nRyan's Maths Game\n");
                printf("\nTo set your amount of questions, enter 1\nTo play the game, enter 2\nTo see your previous score, enter 3\nTo end the program, enter 4\n\n");
                scanf("%d", &GameState);
                while(getchar() != '\n');//prevents infinite loop if wrong character if pressed
            }
        }

        //Set question amount
        while (GameState == 1)
        {
            
            //gamequestion setting
            printf("\n\nHow many questions would you like?\nPlease choose a value between 1 and 5.\n\n");
            scanf("%d", &QuestionAmount);
            
            //error checking for invalid number of questions
            if (QuestionAmount < 1 || QuestionAmount > 5)
            {
                printf("\n\nError, the number inputted is invalid, please try again.\n");
                scanf("%d", &QuestionAmount);

            }

            //reset score counters in preparation for the next game
            WinCounter = RESET;
            LossCounter = RESET;
            QuestionSetState = 1;
            GameState = RESET;//resets the game to the menu
        }//gamestate 1 while loop end

        //to play the game
        while (GameState == 2)
        {

            //game logic
            if (QuestionSetState == 1)
            {
                //preparing player for the game
                printf("\nYou will answer %d questions, good luck!\n", QuestionAmount);

                //game loop
                for (QuizLoop = 0; QuizLoop < QuestionAmount; QuizLoop++)
                {
                    printf("\nQuestion %d\n", QuizLoop +1 );
                    Answers = (QuestionAmount*(QuizLoop+2)) + 12;
                    printf("\n(%d * (%d + 2)) + 12 = \n", QuestionAmount, QuizLoop);
                    scanf("%d", &UserIn);
                    
                    //if you answer right
                    if (UserIn == Answers)
                    {
                        printf("\nCongratulations, you're right!\n");
                        WinCounter = WinCounter +1;
                    }

                    //if you answer wrong
                    else
                    {
                        printf("\nOh no, you're wrong. The answer is %d\n", Answers);
                        LossCounter = LossCounter+1;

                    }
                    //to see if the game has already been played in this instance, to determine if score menu is valid
                    GamePlay = 1;
                    //set question state to zero to make user set questions
                    QuestionSetState = RESET;

                }//end of for loop
                //reset game to base state
                GameState = RESET;
            }

            //Catching and preventing gameplay without questions being set
            else
            {
                printf("\n\nYou seem to have forgotten to set questions. Please set questions to play!\n\n");
                GameState = RESET;
            }
        }//gamestate 2 while loop end

        //to see score
        while (GameState == 3)
        {   
            //preventing score viewing without having played the game
            if(GamePlay == 0)
            {
                printf("\n\nError, you seem to have not played the game yet!\n\n");
                GameState = 0;
            }

            //if the game has been played, display score
            else
            {
                printf("\n\nYou have answered %d questions correct, while you answered %d wrong\n\n", WinCounter, LossCounter);
                printf("\nTo set your amount of questions, enter 1\nTo play the game, enter 2\nTo see your previous score, enter 3\nTo end the program, enter 4\n\n");
                scanf("%d", &GameState);
            }
        }//gamestate 3 while loop end
    } //gamestate 4 while loop end
    
    printf("\nThank you for running my program!\n");
    printf("\n\nCredits: Written by Ryan McLoughlin, C21431604\n\n");
    return 0;
}//end main

