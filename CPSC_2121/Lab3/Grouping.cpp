/*
 * Keenan Grant
 * 9/26/22
 * 003
 * Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string filename) {
    fstream file;
    file.open(filename);
    char cell;
    /*Reads the characters from the file
    and stores them into the grid 2D array*/
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            file >> cell;
            if (cell == 'X') {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }

    /*Pushes back findGroup vectors for the
    groups vector*/
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) {
                groups.push_back(findGroup(i, j));
                coords.clear();
            }
        }
    }
}

//Returns a vector of GridSquare objects
vector<GridSquare> Grouping::findGroup(int r, int c) {
    GridSquare coordinate = GridSquare(r,c);
    if (grid[r][c] == 1) {
        coords.push_back(coordinate);

        //If GridSqaure coordinate is negative
        if (r < 0 || c < 0) {
            coords.pop_back();
        }

        /*Changes 'X' to '.' so it wouln't be
        added to another group*/
        grid[r][c] = 0;

        /*Checks if the coordinate is on one
        of the four corners*/
        if (r == 0 && c == 0) {
            findGroup(r, c + 1);
            findGroup(r + 1, c);
        }
        if (r == 9 && c == 0) {
            findGroup(r, c + 1);
            findGroup(r - 1, c);
        }
        if (r == 0 && c == 9) {
            findGroup(r, c - 1);
            findGroup(r + 1, c);
        }
        if (r == 9 && c == 9) {
            findGroup(r, c - 1);
            findGroup(r - 1, c);
        }

        /*Checks if the coordinate is on
        the edge of the square*/
        if (c == 0 && r > 0 && r < 9) {
            findGroup(r, c + 1);
            findGroup(r + 1, c);
            findGroup(r - 1, c);
        }
        if (r == 0 && c > 0 && c < 9) {
            findGroup(r, c - 1);
            findGroup(r, c + 1);
            findGroup(r + 1, c);
        }
        if (c == 9 && r > 0 && r < 9) {
            findGroup(r - 1, c);
            findGroup(r, c - 1);
            findGroup(r + 1, c);
        }
        if (r == 9 && c > 0 && c < 9) {
            findGroup(r - 1, c);
            findGroup(r, c - 1);
            findGroup(r, c + 1);
        }

        /*Checks if the coordinate is in
        the middle*/
        if (r > 0 && c > 0 && r < 9 && c < 9) {
            findGroup(r, c + 1);
            findGroup(r - 1, c);
            findGroup(r, c - 1);
            findGroup(r + 1, c);
        }
    }
    return coords;
}
//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/*int main() {
    Grouping input1("input3.txt");
    input1.printGroups();
    
    return 0;
}*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const {
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() { //return row value
    return row;
}

int GridSquare::getCol() { //return column value
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj) {
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() { //Displays grid's groups of squares
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() { //Needed in unit tests
    return groups;
}