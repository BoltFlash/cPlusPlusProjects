#include "review.h"
#include <iostream>
#include <string>

using namespace std;

void ReadStdIn2() {
    string input;
    int count = 0;

    cin >> input;
    
    while (input != "q") {
        count++;
        cin >> input;
    }

    cout << count << endl;
}