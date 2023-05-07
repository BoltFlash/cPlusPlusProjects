/*
    Keenan Grant
    CPSC 2120: 002
    9/6/22
*/

#include "review.h"

using namespace std;

int Fibonacci(int a) {
    if (a == 0) {
        return 1;
    }
    else if (a == 1) {
        return 1;
    }
    else {
        return Fibonacci(a - 1) + Fibonacci(a - 2);
    }
}
