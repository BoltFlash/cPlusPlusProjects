/*
    Keenan Grant
    CPSC 2070: 002
    11/28/22
*/

#include "minHeap.h"
#include <vector>

using namespace std;

//Inserts a value into the heap
void minHeap::insert(int value) {
    heap.push_back(value);
    //Up-heaping the new value until the heap property is satisfied
    int child = heap.size() - 1;
    siftUp(child);
}

//Removes the minimum value from the heap
int minHeap::removeMin() {
    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.pop_back();
    //Heapifying the original root node until the heap property is satisfied
    siftDown(0);
    return temp;
}

//Organizing a min heap by moving an element up
void minHeap::siftUp(int pos) {
    int parent = (pos - 1) / 2;
    int child = pos;

    //Repeatedly swapping the parent and child until the heap property is satisfied
    while (heap[parent] > heap[child]) {
        int temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        //Making the parent the new child incase the heap property is still violated
        child = parent;
        parent = (parent - 1) / 2;
    }
}

//Organizing a min heap by moving an element down
void minHeap::siftDown(int pos) {
    int parent = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int swap = -1;

    if (left < heap.size() && heap[left] < heap[parent]) {
        swap = left;
    }
    if (right < heap.size() && heap[right] < heap[parent]) {
        if (swap == -1) {
            swap = right;
        }
        else if (heap[right] < heap[left]) {
            swap = right;
        }
    }

    if (swap != -1) {
        int temp = heap[swap];
        heap[swap] = heap[parent];
        heap[parent] = temp;
        //A recursive call so the heapification can fully go through
        siftDown(swap);
    }
}

//Heap constructor for new data
minHeap::minHeap(vector<int> data) {
    //Clears the heap for new data to replace
    heap.clear();
    //Inserts the data into the heap
    for (int i = 0; i < data.size(); i++) {
        heap.push_back(data[i]);
    }
    //Building the heap from the bottom-up
    for (int i = heap.size() - 1; i >= 0; i--) {
        siftDown(i);
    }
}