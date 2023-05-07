#include "review.h"
#include <string>
#include <iostream>

using namespace std;

int WriteOut(string output) {
    cout << output;
    return 1;
}

int WriteOut(int output) {
    cout << output;
    return 2;
}

int WriteOut(double output) {
    cout << output;
    return 3;
}