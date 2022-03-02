/*
Lo Shu Magic Square

1. create main() that declare a empty 2D array, call generateSquare() and isMagicSquare() function
2. implement generateSquare() function that generate square to be tested
3. implement isMagicSquare() function that return "true" if the square is Lo Shu Magic Square and "false" if not
4. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum {False, True, SIDE = 3, SQUARE_AREA = 9, MUST_HAVE_SUM = 15, MAX_ATTEMPT = 1000000};

/* Function Declaration Prototype */
int isMagicSquare(int square[SIDE][SIDE]);
void displaySquare(int square[SIDE][SIDE]);
void populateSquare(int square[SIDE][SIDE]);

/* MAIN */
int main(void)
{
    time_t t;
    srand((unsigned) time(&t));
    int trialCount = 0;
    do
    {
        int test[][3] = {0,0,0,0,0,0,0,0,0};
        populateSquare(test);
        if(isMagicSquare(test))
        {
            displaySquare(test);
            printf("\nCongrats, we found a Lo Shu magic square after %d trials!!!\n", trialCount);
            return 0;
        }
        else trialCount++;
    } while (trialCount < MAX_ATTEMPT);
    printf("\nIt took too long to find, let's rerun the program...\n");
}
void populateSquare(int square[SIDE][SIDE])
{
    // Initialize an array
    int random_1D_array[SQUARE_AREA] = {1,2,3,4,5,6,7,8,9};
    // shuffle array
    for (int i = 0; i < SQUARE_AREA; i++) { 
        int randomIndex = rand() % SQUARE_AREA;
        int temp = random_1D_array[i];
        random_1D_array[i] = random_1D_array[randomIndex];
        random_1D_array[randomIndex] = temp;
    }
    // populate the square with random number from 1D array
    int pos = 0;
    for (int row = 0; row < SIDE; row++){
        for (int col = 0; col < SIDE; col++){
            square[row][col] = random_1D_array[pos++];
        }
    }
}
int isMagicSquare(int square[SIDE][SIDE])
{
    // find sum and compare the 2 diagonal sum with 15
    int incDiagonal = 0, decDiagonal = 0;
    for (int i = 0; i < SIDE; i++)
        decDiagonal= decDiagonal + square[i][i];
    for (int i = 0; i < SIDE; i++)
        incDiagonal = incDiagonal + square[i][SIDE-1-i];
    if(decDiagonal != incDiagonal)  return False;
    // find sum and compare each row/column with 15
    for (int row = 0; row < SIDE; row++){
        int rowSum = 0, columnSum = 0;
        for (int col = 0; col < SIDE; col++){
            rowSum += square[row][col];
            columnSum += square[col][row];
        }
        if(rowSum != MUST_HAVE_SUM || columnSum != MUST_HAVE_SUM)   return False;
    }
    return True;
}
void displaySquare(int square[SIDE][SIDE])
{
    printf("\n*********************");
    printf("\nThe square content:\n");
    for (int row = 0; row < SIDE; row++){
        printf("\n");
        for (int col = 0; col < SIDE; col++){
            printf("| %d ", square[row][col]);
        }
        printf("|");
    }
}