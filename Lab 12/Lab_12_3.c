//headers
#include <stdio.h>


//symbolic name block
#define SIZE 3


//function signatures
void HighestVal(int []);
void LowestVal(int []);


//beginning main
int main()
{
    int ValArray[SIZE];
    int i = 0;
    for(i = 0; i<SIZE; i++)
    {
        printf("Please enter value %d\n\n", i+1);
        scanf("%d", &ValArray[i]);
    }
    

    HighestVal(ValArray);
    LowestVal(ValArray);

}
//HighestVal functionv
void HighestVal(int HValArray[])
{
    	int biggest = HValArray[0];//making sure that biggest is always a value in the array
        int i = 0;
        while (i < SIZE)//determining size
            {
                if (HValArray[i]>biggest)//if the array is larger than biggest, it must be the largest so far tested
                {
                    biggest = HValArray[i];
                    i = i + 1;
                }
                else
                {
                    i = i + 1;
                }
            }
            
        printf("%d is the biggest\n\n", biggest);
        
}

void LowestVal(int LValArray[])
{
    	int Smallest = LValArray[0];//to ensure that the smallest doesnt always say zero
        int i = 0;
        while (i < SIZE)
        {
            if (LValArray[i]<Smallest)
            {
                Smallest = LValArray[i];
                i = i + 1;
            }
            else
            {
                i = i + 1;
            }
        }
        printf("%d is the smallest\n\n", Smallest);


}