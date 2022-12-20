/*
 * Keenan Grant
 * 10/9/22
 * 003
 * Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {

}

template <class T>
int partition(std::vector<T> &lst, int low, int high) {
    /*Selects a random element and swaps it
    with the first element*/
    int randIndex = rand() % lst.size();
    T pivotValue = lst[randIndex];
    int pivotIndex = low;

    T temp = lst[low];
    lst[low] = pivotValue;
    lst[randIndex] = temp;

    /*If a value is less than the pivot value, the
    pivotIndex is increased and the value is swapped
    with value at the new pivotIndex*/
    for (int i = low + 1; i <= high; i++) {
        if (lst[i] < pivotValue) {
            pivotIndex++;
            temp = lst[pivotIndex];
            lst[pivotIndex] = lst[i];
            lst[i] = temp;
        }
    }

    /*When the loop is done, the pivotValue is swapped
    with the number at the pivotIndex*/
    temp = lst[pivotIndex];
    lst[pivotIndex] = pivotValue;
    lst[low] = temp;

    return pivotIndex;
}

//Uses recursion to implement quick sort
template <class T>
std::vector<T> quickSortFind(std::vector<T> &lst, int low, int high) {
    if (low < high) {
        int pivot = partition(lst, low, high);
    
        quickSortFind(lst, low, pivot - 1);
        quickSortFind(lst, pivot + 1, high);
    }

    return lst;
}

//Calls quickSortFind to implement three parameters
template <class T>
std::vector<T> quickSort(std::vector<T> lst) {
    std::vector<T> temp = quickSortFind(lst, 0, lst.size() - 1);

    return temp;
}