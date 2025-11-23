#include "functions.h"

using namespace std;

int main(void)
{
int board[16][16] = {
    {5, 1, 6, 8, 4, 9, 7, 3, 2},
    {3, 0, 7, 6, 0, 5, 0, 0, 0},
    {8, 0, 9, 7, 0, 0, 0, 6, 5},
    {1, 3, 5, 0, 6, 0, 9, 0, 7},
    {4, 7, 2, 5, 9, 1, 0, 0, 6},
    {9, 6, 8, 3, 7, 0, 0, 5, 0},
    {2, 5, 3, 1, 8, 6, 0, 7, 4},
    {6, 8, 4, 2, 0, 7, 5, 0, 0},
    {7, 9, 1, 0, 5, 0, 6, 0, 8},
};

    bool rez = SudokuSolver(board,3);
    cout<<"puzzleul e rezolvat:" << rez<<endl;
    for(int i = 0; i < 9; i++) {
    if(i % 3 == 0 && i != 0) cout << "------+-------+------" << endl;
    
    for(int j = 0; j < 9; j++) {
        if(j % 3 == 0 && j != 0) cout << "| ";
        cout << board[i][j] << " ";
    }
    cout << endl;
}
}