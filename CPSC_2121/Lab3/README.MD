Consider an NxN grid in which some squares are occupied. Two squares belong to the same group if they share a common edge (not just a corner). In the figure there is one group of four occupied squares, three groups of two occupied squares, and two individual occupied squares.

.........X
...XX....X
..........
....X..X..
...X...X..
.......XX.
....XX....
..........
..........
..........
In this lab, in the Grouping.cpp file from the starter code, you are to implement the constructor for a C++ class called Grouping along with a recursive member function findGroup that contains the following:

grid: a 2D int array with 10 rows and 10 columns.
groups: a vector containing vectors of the locations of occupied squares (vector<vector<GridSquare>>) for each group
a constructor that reads a file into the array and then processes this array using findGroup to populate each element in groups with the locations of occupied squares in that group. Each line of the file is a row of the array. The character . should be converted to 0, and any other character converted to 1
a recursive method findGroup. (Your choice of parameter list, but mine is just: int row, int col.) This function should probably update the array as it goes.
the printGroups function which displays each group's occupied squares (already implemented)
The Grouping.h file includes the definition for the GridSquare class (in addition to the Grouping class) which contains the row and column value for any occupied square on the grid. This class is fully implemented and does not need to be modified. In addition to the constructors (the parameterized constructor is the one to be used), there are two methods for accessing the row and column values (getRow / getCol), an operator== function to check if two GridSquare objects have the same row/column values by using the == operator, and an operator<< (friend) function in order to use GridSquare objects with stream insertion (used in the printGroups function).

A main function is included to test the construction of a Grouping object reading input1.txt (also included in the starter code) and then display the contents of each group using printGroups.

For example, for the sample grid above, the output of your program should be something like (not including comments): Note that your ordering might be different

Group 1:  (0,9) (1,9)       // the two occupied squares in upper right corner
Group 2:  (1,3) (1,4)       // the two occupied squares in row 1
Group 3:  (3,4)
Group 4:  (3,7) (4,7) (5,7) (5,8)
Group 5:  (4,3)
Group 6:  (6,4) (6,5)
You may include additional private helper functions, if you wish. Submit Grouping.cpp with the implemented parameterized construtor for Grouping and the implemented recursive function findGroup along with Grouping.h.
