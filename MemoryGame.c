#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 10

bool includes (int arr[], int length, int value);

bool includes (int arr[], int length, int value)
{
    for (int i; i < length; i++)
    {
        if (value == arr[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int creatingFirstArray (int arr[])
{
    int tempArr[SIZE]; // Store integers that are already signed to a random index in the array.
    for (int index = 0; index < SIZE; index++)
    {
        int intervalNum = (rand() % SIZE) + 1; // We want number to be in interval [1,10] which will be input taken from the user.
        while (true)
        {
            if(includes(tempArr[SIZE], SIZE, intervalNum))
            {
                srand(time(NULL));
                intervalNum = (rand() % SIZE) + 1;
            }
            else
            {
                break;
            }
        }
        tempArr[index] = intervalNum;
        arr[index] = intervalNum;
    }
    return arr;
}

int creatingSecondArray (int arr[])
{
    int tempArr2[SIZE]; // Store integers that are already signed to a random index in the array.
    for (int index = 0; index < SIZE; index++)
    {
        int intervalNum = (rand() % SIZE) + 1; // We want number to be in interval [1,10] which will be input taken from the user.
        while (true)
        {
            if(includes(tempArr2[SIZE], SIZE, intervalNum))
            {
                srand(time(NULL));
                intervalNum = (rand() % SIZE) + 1;
            }
            else
            {
                break;
            }
        }
        tempArr2[index] = intervalNum;
        arr[index] = intervalNum;
    }
    return arr;
}

int main (void)
{
    // Let this game be in 10x10 pattern. 
    int arrOfFirstPickedCard[SIZE];
    int arrOfSecondPickedCard[SIZE];
    // Now let's assign some random values to each index of an array and the other one will have the same values.
    // However, as we know that rand() function in c does not work properly(?) since it will give same values each time we run the program.
    // To fix that issue, we can use current time as a seed to srand() function and generate "real" random values.
    // That is why I added time header to the program.
    srand(time(NULL)); // Random number generator
    creatingFirstArray(arrOfFirstPickedCard);
    creatingSecondArray(arrOfSecondPickedCard);
    /* First of all, I will take an input from the user to pick a card between 1 to 10.
    Let's say we picked 5; now let's store this value. Then we will need to pick another card from the other deck again in the same interval.
    Assume that we chose 7; now let's store this value too. Finally, check if arrOfFirstPickedCard[5] == arrOfSecondPickedCard[7] 
    If true, then counter += 1. This loop keeps going and when the counter == 10, the player wins the game. 
    However, there is a point we need to be careful about: If the player chooses the same varian again and again such as 5 and 7 repeatedly,
    the player would be able to beat the game easily by picking the same cards.
    TO PREVENT THIS: 
    First Option: Delete those values from the arrays list.
    Second Option: Create another array where you store picked values and do not let player choose from that list (array) again. 
    NOTE THAT: In second option, we will need 2 arrays for both first picking card array and second picking card array since if 5 and 7 are 
    chosen, the player should be able to choose 7 and 5 as these 2 situations are 2 different cases. */
    return 0;
}