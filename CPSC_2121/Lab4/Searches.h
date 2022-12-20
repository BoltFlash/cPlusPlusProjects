/*
 * Keenan Grant
 * 10/9/22
 * 003
 * Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <iostream>

/*Linearily searches through vector from start to
finish to find the target*/
template <class T>
int linearSearch(std::vector<T> data, T target){
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

/*Binarily searches through vector by finding
the middle element of each cycle until the target
is found*/
template <class T>
int binarySearch(std::vector<T> data, T target){
    int low = 0;
    int high = data.size() - 1;
    int mid;
    int targetIndex = 0;
    bool loop = false;
    bool targetFound = false;

    //Finds the index of the target
    for (int i = 0; i < data.size() - 1; i++) {
        if (data[i] == target) {
            targetIndex = i;
            targetFound = true;
        }
    }

    //Binary search
    while (!loop && targetFound) {
        mid = (high + low) / 2;
        if (mid == targetIndex) {
            return mid;
        }
        else if (mid < targetIndex) {
            low = mid + 1;
        }
        else if (mid > targetIndex) {
            high = mid - 1;
        }
    }
    return -1;
}
