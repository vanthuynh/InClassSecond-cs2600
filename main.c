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

enum {False, True, SIDE = 3, SQUARE_AREA = 9, MUST_HAVE_SUM = 15};

/* Function Declaration Prototype */
int isMagicSquare(int square[SIDE][SIDE]);
void displaySquare(int square[SIDE][SIDE]);
void populateSquare(int square[SIDE][SIDE]);

/* MAIN */
int main(void)
{
    int testMatrix[SIDE][SIDE] = {{1,2,3},{4,5,6},{7,8,9}};
    displaySquare(testMatrix);
    if(isMagicSquare(testMatrix))
        printf("\nCongrats, the square is a Lo Shu magic square!!!\n");
    else  printf("\nSorry, the square is NOT a Lo Shu magic square!!!\n");
    /*
    time_t t;
    int min = 1;

    // generate random number from min and max value
    srand((unsigned) time(&t));
    int randomNum = rand() % max;
    */
    return 0;
}
void populateSquare(int square[SIDE][SIDE])
{
    // int default_1D_array[] = {1,2,3,4,5,6,7,8,9};
    // for (int i = 0; i < 13; i++) {    // shuffle array
    // int randomIndex = rand() % 13;
    //     int temp = default_1D_array[i];
    //     default_1D_array[i] = default_1D_array[randomIndex];
    //     default_1D_array[randomIndex] = temp;
    // }
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    
}
int isMagicSquare(int square[SIDE][SIDE])
{
    int rowSum = 0, columnSum = 0;
    int incDiagonal = 0, decDiagonal = 0;
    // find sum and compare the 2 diagonal sum with 15
    for (int i = 0; i < SIDE; i++)
        decDiagonal= decDiagonal+ square[i][i];
    for (int i = 0; i < SIDE; i++)
        incDiagonal = incDiagonal + square[i][SIDE-1-i];
    // find sum and compare each row/column with 15
    for (int row = 0; row < SIDE; row++){
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