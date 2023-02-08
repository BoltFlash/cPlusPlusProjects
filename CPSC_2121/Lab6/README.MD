In this lab exercise, you will use “spatial hashing” to find the closest pair among 1 million points spread uniformly across a unit square in the 2D plane. Although this problem is easily solved in Θ(n2) time by comparing all pairs of points, this solution is too slow for input sizes n on the order of 100,000 to 1 million, as is the case here.

Download the starter code which includes two text files each containing a list of points. You will implement the function closestPair() which takes a string parameter for the file with the list of points to open. This function will open and read the file then find the distance between the closest pair of points which will be returned as a double type value.

The two text files included: points100.txt and points250k.txt contain 100 and 250,000 points respectively. The general format is the first line contains the number of points in the file and the remaining lines will contain two space-separated real numbers per line giving the x and y coordinates of a point. All points (x, y) live strictly inside the unit square described by 0 ≤ x < 1 and 0 ≤ y < 1. Remember that the distance between two points (x1, y1) and (x2, y2) is given by sqrt ((x1 − x2)^2 + (y1 − y2)^2).

As a small caveat, the C++ library has a function named “distance” already defined (which does something other than computing geometric distance above), so you if you write a function to compute distance, you should probably give it a name other than “distance” or else obscure compiler errors might result.

To find the closest pair of points quickly, you will divide the unit square containing the points into a b × b grid of square “cells”, each representing a 2D square of size 1/b × 1/b. Each point should be “hashed” to the cell containing it. For example, if you are storing the x coordinate of a point in a “double” variable named x, then (int)(x * b) will scale the coordinate up by b and round down to the nearest integer; the result (in the range 0 . . . b − 1) can be used as an one of the indices into your 2D array of cells. The other index is calculated the same way, only using the y coordinate.

After hashing, each point needs only to be compared to the other points within its cell, and the 8 cells immediately surrounding its cell – this should result in many fewer comparisons than if we simply compared every point to every other point. You will need to select an appropriate value of b as part of this lab exercise. Keep in mind that the value of b should scale appropriately based on the number of points in the unit square, for example b will need to be a greater value when working with 250,000 points than working with 100 points. You may want to consider what are the dangers in setting b too low or too high.

Since b must scale with the number of points (giving b x b cells) and the number of points within a cell will vary from one cell to another, a dynamically allocated data structure must be used. You may use the STL vector class for this. One approach that can be used is to have a 2D vector (a vector of vectors) representing the cells with each cell having a vector of points (the resulting data type would be vector<vector<vector<point>>>).

The closestPair() function should consist of the following major steps:

1. Open the file and read the number of points that will be listed to determine an appropriate value for b (the number of divisions along the x-axis and y-axis within the unit square for spatial hashing).

2. Initialize the b x b array of cells to each contain an empty set of points.

3. Read the remainder of the input file adding each point to the appropiate cell it maps to.

4. For each point compare it to all the points within its cell and the 8 adjacent cells; remember the smallest distance obtained during this process.

5. Return the minimum distance.

Part of this lab also involves figuring out a good choice for the value of b. Please include in a comment in your code a brief description of why you think your choice of b is a good one (this will count for 5 of the 10 manual grade points). Submit the file closestPair.cpp with the implemented closestPair() function.
