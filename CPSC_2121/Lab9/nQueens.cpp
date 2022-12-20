/*
 * Keenan Grant
 * 11/21/22
 * 003
 * Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

//Determines if a queen can be placed in a spot or not
bool niceSpot(vector<vector<int>> &board, int r, int c, int n) {
    //Checks the up direction
    for (int i = r; i >= 0; i--) {
        if (board[i][c] == 1) {
            return false;
        }
    }

    //Checks up left diagonal direction
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    //Checks up right diagonal direction
    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

//A recursive function that finds all of the solutions of the n queens problem
int permutation(vector<vector<int>> &board, int r, int n) {
    int solutions = 0;

    //Base case to end recursion
    if (r == n) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (niceSpot(board, r, i, n)) {
            //Places a queen in that spot
            board[r][i] = 1;
            //Recursive call to place the rest of the queens on the board
            solutions += permutation(board, r + 1, n);
            //Clears the board for more solutions to be found
            board[r][i] = 0;
        }
    }
    return solutions;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n) {
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions

    //Creates the chess board
    vector<vector<int>> board(n, vector<int>(n, 0));

    return permutation(board, 0, n);
}

// int main()
// {
//     cout << "1: " << nQueens(1) << endl;
//     cout << "2: " << nQueens(2) << endl;
//     cout << "3: " << nQueens(3) << endl;
//     cout << "4: " << nQueens(4) << endl;
//     cout << "5: " << nQueens(5) << endl;
//     cout << "6: " << nQueens(6) << endl;
//     cout << "7: " << nQueens(7) << endl;
//     cout << "8: " << nQueens(8) << endl;
//     cout << "9: " << nQueens(9) << endl;
//     cout << "10: " << nQueens(10) << endl;
//     cout << "11: " << nQueens(11) << endl;
//     cout << "12: " << nQueens(12) << endl;
//     return 0;
// }