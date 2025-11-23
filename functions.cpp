#include "functions.h"

bool SudokuSolver(int board[16][16],int dimension)
{
    bool result = false;
    for(int i=0; i < (dimension*dimension); i++)
    {
        for(int j=0; j<(dimension*dimension); j++)
        {
            if(0==board[i][j])
            {
                int usedNumbers[16]={0};
                lineSolver(board,dimension,i,usedNumbers);
                columnSolver(board,dimension,j,usedNumbers);
                boxSolver(board,dimension,i,j,usedNumbers);    
                for(int x = 0; x < (dimension * dimension); x++)
                {
                    if(0 == usedNumbers[x])
                    {
                        board[i][j] = x+1;
                        result = SudokuSolver(board,dimension);
                        if(true == result)
                        {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                if(0 == board[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void lineSolver(int board[16][16],int dimension,int index, int usedNumbers[16])
{
    for(int i = 0; i < (dimension*dimension); ++i)
    {
        if(! (board[index][i] == 0))
        {
            usedNumbers[board[index][i]-1] = 1;
        }
    }
}

void columnSolver(int board[16][16],int dimension, int index, int usedNumbers[16])
{
    for(int j = 0; j < (dimension * dimension); j++)
    {
        if(! (board[j][index] == 0))
        {
            usedNumbers[board[j][index] - 1] = 1;
        }
    }
}

void boxSolver(int board[16][16], int dimension, int i, int j, int usedNumbers[16])
{
    int startrow = (i/dimension) * dimension;
    int startcolumn = (j/dimension) * dimension;
    for(int k=startrow;k<(startrow+dimension);k++)
    {
        for(int l=startcolumn; l<(startcolumn+dimension);l++)
        {
            if(! (board[k][l] == 0))
            {
                usedNumbers[board[k][l] - 1] = 1;
            }
        }
    }
}
