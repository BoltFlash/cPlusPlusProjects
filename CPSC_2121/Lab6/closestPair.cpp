/*
 * Keenan Grant
 * 10/25/22
 * 003
 * Lab 6: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct point
{
    double x = 0;
    double y = 0;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);
bool distanceFound(point, point, vector<vector<point>>);
double findDistance(point, vector<point>, vector<vector<point>>);

// int main()
// {
//     double min;
//     string filename;
//     cout << "File with list of points within unit square: ";
//     cin >> filename;
//     min = closestPair(filename);
//     cout << setprecision(16);
//     cout << "Distance between closest pair of points: " << min << endl;
//     return 0;
// }

double closestPair(string filename) {
  fstream file(filename);

  //Finds the number of points the file has and determines its b value
  int points = 0;
  file >> points;
  /*b is found by taking the square root of how many points are in the file.
  Any less could cause too many points in a cell and any more could cause too
  many cells.*/
  int b = sqrt(points);

  //Creates the grid by initializing the rows and columns of size b
  vector<vector<vector<point>>> plane(b, vector<vector<point>>(b));

  //Inserts the points into the plane by spatial hashing
  for (int i = 0; i < points; i++) {
    point coord;
    file >> coord.x;
    file >> coord.y;
    int xPos = (int)(coord.x * b);
    int yPos = (int)(coord.y * b);
    plane[xPos][yPos].push_back(coord);
  }

  double minimum = 2;
  double smallestDistance = 2;
  vector<vector<point>> comparedPoints;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      for (point thePoint : plane[i][j]) {
        /*Checks if the element is on one
        of the four corners*/
        //Top left
        if (i == 0 && j == 0) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i + 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Bottom left
        if (i == b - 1 && j == 0) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i - 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Top right
        if (i == 0 && j == b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i + 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j - 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Bottom right
        if (i == b - 1 && j == b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i - 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j - 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }

        /*Checks if the element is on
        the edge of the plane*/
        //Left side
        if (j == 0 && i > 0 && i < b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i - 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j + 1], comparedPoints));
          // i + 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Top side
        if (i == 0 && j > 0 && j < b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i + 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j - 1], comparedPoints));
          // i + 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Right side
        if (j == b - 1 && i > 0 && i < b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i - 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j - 1], comparedPoints));
          // i + 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j - 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }
        //Bottom side
        if (i == b - 1 && j > 0 && j < b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i - 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j - 1], comparedPoints));
          // i - 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }

        /*Checks if the element is in
        the middle of the plane*/
        if (i > 0 && j > 0 && i < b - 1 && j < b - 1) {
          vector<double> distances;
          //Finds distances within the cell
          distances.push_back(findDistance(thePoint, plane[i][j], comparedPoints));
          // i, j + 1
          distances.push_back(findDistance(thePoint, plane[i][j + 1], comparedPoints));
          // i - 1, j
          distances.push_back(findDistance(thePoint, plane[i - 1][j], comparedPoints));
          // i, j - 1
          distances.push_back(findDistance(thePoint, plane[i][j - 1], comparedPoints));
          // i + 1, j
          distances.push_back(findDistance(thePoint, plane[i + 1][j], comparedPoints));
          // i - 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j - 1], comparedPoints));
          // i - 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i - 1][j + 1], comparedPoints));
          // i + 1, j - 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j - 1], comparedPoints));
          // i + 1, j + 1
          distances.push_back(findDistance(thePoint, plane[i + 1][j + 1], comparedPoints));
          minimum = *min_element(distances.begin(), distances.end());
        }

        if (minimum < smallestDistance) {
          smallestDistance = minimum;
        }
      }
    }
  }
  
  return smallestDistance;
}

//Checks if the distance between two points has already been found
bool distanceFound(point one, point two, vector<vector<point>> distances) {
  vector<point> config1 = {one, two};
  vector<point> config2 = {two, one};
  for (int i = 0; i < distances.size(); i++) {
    if (config1 == distances[i] || config2 == distances[i]) {
      return true;
    }
  }
  return false;
}

//Finds the distance between two points
double findDistance(point temp, vector<point> cell, vector<vector<point>> distances) {
  double difference;
  double distance = 2;
  bool same = false;
  for (int i = 0; i < cell.size(); i++) {
    if (temp.x == cell[i].x && temp.y == cell[i].y) {
      same = true;
    }
    if (!distanceFound(temp, cell[i], distances) && !same) {
      difference = sqrt(pow((temp.x - cell[i].x), 2) + pow((temp.y - cell[i].y), 2));
      vector<point> one = {temp, cell[i]};
      distances.push_back(one);
      if (distance > difference) {
        distance = difference;
      }
    }
  }
  return distance;
}

//Overloaded == operator to work with the point struct
bool operator==(const point& lhs, const point& rhs) {
  if (lhs.x == rhs.x && lhs.y == rhs.y) {
    return true;
  }
  return false;
}