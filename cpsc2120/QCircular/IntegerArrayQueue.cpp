/*
    Keenan Grant
    CPSC 2070: 002
    9/28/22
*/

#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    if ((back + 2) % size == front) {
        return false;
    }
    else {
        if (back == (size - 1)) {
            back = 0;
            array[back] = value;
        }
        else {
            back++;
            array[back] = value;
        }
    }
    return true;
}

int IntegerArrayQueue::dequeue() {
    int num = 0;
    if ((back + 1) % size == front) {
        return 0;
    }
    else {
        if (front == (size - 1)) {
            front = 0;
        }
        front++;
        num = array[front - 1];
        return num;
    }
}