/*
 * Keenan Grant
 * 9/12/22
 * 001
 * Lab 1: Linked List Based Stacks and Queues
 */

#pragma once
#include "List.h"

//This class represents a Queue implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListQueue{

 private:
  List<T> queue;

 public:
  ListQueue();
  ~ListQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  //Print the name and this ListQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    queue.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListQueue by initializing this ListQueue's instance variables
template <class T>
ListQueue<T>::ListQueue(){
  queue = nullptr;
}

//Destroy all nodes in this ListQueue to prevent memory leaks
template <class T>
ListQueue<T>::~ListQueue(){
  List<T> *trash = queue;
  while (trash != nullptr) {
    queue = queue -> next;
    trash -> next = nullptr;
    delete trash;
    trash = queue;
  }
}

//Return the size of this ListQueue
template <class T>
int ListQueue<T>::size(){
  List<T> *temp = queue;
  int mySize = 0;
  while (temp) {
    mySize++;
    temp = temp -> next;
  }
  return mySize;
}

//Return true if this ListQueue is empty
//Otherwise, return false
template <class T>
bool ListQueue<T>::empty(){
  if (queue == nullptr) {
    return true;
  }
  else {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this ListQueue in its correct position
template <class T>
void ListQueue<T>::enqueue(T value){
  if (empty()) {
    queue = new Node(value);
    List<T> *temp = queue;
    while (temp -> next != nullptr) {
      temp = temp -> next;
    }
    temp -> next = nullptr;
  }
  else {
    List<T> *temp = queue;
    while (temp -> next != nullptr) {
      temp = temp -> next;
    }
    temp -> next = new Node(value);
  }
}

//Dequeue an element from the queue.
//Note that here that means both removing it from the list
//AND returning the value
template <class T>
T ListQueue<T>::dequeue(){
  List<T> *temp = queue;
  List<T> *returnVal = temp;
  queue = temp -> next;
  delete temp;
  return returnVal;
}