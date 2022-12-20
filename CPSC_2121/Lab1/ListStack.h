/*
 * Keenan Grant
 * 9/12/22
 * 001
 * Lab 1: Linked List Based Stacks and Queues
 */

#pragma once
#include "List.h"

//This class represents a Stack implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListStack{

 private:
  List<T> stack;

 public:
  ListStack();
  ~ListStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  //Print the name and this ListStack's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    stack.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListStack by initializing this ListStack's instance variables
template <class T>
ListStack<T>::ListStack(){
  stack = nullptr;
}

//Destroy all nodes in this ListStack to prevent memory leaks
template <class T>
ListStack<T>::~ListStack(){
  List<T> *trash = stack;
  while (trash != nullptr) {
    stack = stack -> next;
    trash -> next = nullptr;
    delete trash;
    trash = stack;
  }
}

//Return the size of this ListStack
template <class T>
int ListStack<T>::size(){
  List<T> *temp = stack;
  int mySize = 0;
  while (temp) {
    mySize++;
    temp = temp -> next;
  }
  return mySize;
}

//Return true if this ListStack is empty
//Otherwise, return false
template <class T>
bool ListStack<T>::empty(){
  return stack == nullptr;
}

//Create a node with value <value> and push it onto the stack
template <class T>
void ListStack<T>::push(T value){
  stack = new Node(value);
}

//Pop a node from the Stack.
//Note that here that includes both removing the node from the stack
//AND returning its value.
template <class T>
T ListStack<T>::pop(){
  List<T> *temp = stack;
  List<T> *returnVal;
  while (temp -> next != nullptr) {
    temp = temp -> next;
  }
  returnVal = temp -> next;
  delete temp -> next;
  return returnVal;
}