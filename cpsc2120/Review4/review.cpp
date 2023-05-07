#include "review.h"
#include <iostream>
#include <string>

using namespace std;

void ReadWrite() {
    string input;
    string temp;

    cin >> input;
    
    while (input != "q") {
        temp.append(input);
        temp.append(" ");
        cin >> input;
    }

    cout << temp << endl;
}