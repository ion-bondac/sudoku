#pragma once

#include <iostream>

bool SudokuSolver(int board[16][16],int dimension);
void lineSolver(int board[16][16],int dimension,int index, int usedNumbers[16]);
void columnSolver(int board[16][16],int dimension, int index, int usedNumbers[16]);
void boxSolver(int board[16][16], int dimension, int i, int j, int usedNumbers[16]);
