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
enum {False, True, SIDE = 3, SQUARE_AREA = 9, MUST_HAVE_SUM = 15, MAX_ATTEMPT = 5};

/* Function Declaration Prototype */
int isMagicSquare(int square[SIDE][SIDE]);
void displaySquare(int square[SIDE][SIDE]);
void populateSquare(int square[SIDE][SIDE]);

/* MAIN */
int main(void)
{
    // int testMatrix[SIDE][SIDE] = {{1,2,3},{4,5,6},{7,8,9}};
    // displaySquare(testMatrix);
    // if(isMagicSquare(testMatrix))
    //     printf("\nCongrats, the square IS a Lo Shu magic square!!!\n");
    // else  printf("\nSorry, the square IS NOT a Lo Shu magic square!!!\n");
    // int test2[SIDE][SIDE] = {4,9,2,3,5,7,8,1,6};
    // // populateSquare(test2);
    // displaySquare(test2);
    // if(isMagicSquare(test2))
    //     printf("\nCongrats, the square IS a Lo Shu magic square!!!\n");
    // else  printf("\nSorry, the square IS NOT a Lo Shu magic square!!!\n");
    // int test1[SIDE][SIDE] = {4,3,8,9,5,1,2,7,6};
    // // populateSquare(test1);
    // displaySquare(test1);
    // if(isMagicSquare(test1))
    //     printf("\nCongrats, the square IS a Lo Shu magic square!!!\n");
    // else  printf("\nSorry, the square IS NOT a Lo Shu magic square!!!\n");
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
        else
        {
            trialCount++;
            displaySquare(test);
        }
    } while (trialCount < MAX_ATTEMPT);
    printf("\nIMPOSSIBLE\n");
}
void populateSquare(int square[SIDE][SIDE])
{
    time_t t;
    // Init random number generator
    srand((unsigned) time(&t));
    int random_1D_array[SQUARE_AREA] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < SQUARE_AREA; i++) {    // shuffle array
        int randomIndex = rand() % SQUARE_AREA;
        int temp = random_1D_array[i];
        random_1D_array[i] = random_1D_array[randomIndex];
        random_1D_array[randomIndex] = temp;
    }
    for (size_t i = 0; i < 9; i++)
    {
        printf(" - %d", random_1D_array[i]);
    }
    // populate the square with random number from 1D array
    int pos = 0;
    for (size_t row = 0; row < SIDE; row++){
        for (size_t col = 0; col < SIDE; col++){
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