/*
 * Keenan Grant
 * 9/12/22
 * 001
 * Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T> *temp = start;
  while (temp != nullptr) {
    Node<T> *trash = temp;
    temp = temp -> next;
    delete trash;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  mySize = 0;
  Node<T> *temp = start;
  while (temp) {
    mySize++;
    temp = temp -> next;
  }
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if (size() == 0) {
    return true;
  }
  else {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> *newNode = new Node<T>(value);
  if (empty()) {
    start = new Node<T>(value);
  }
  else {
    Node<T> *newNode = new Node<T>(value);
    newNode -> next = start;
    start = newNode;
  }
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  if (empty()) {
    start = new Node<T>(value);
  }
  else {
    Node<T> *temp = start;
    while (temp -> next != nullptr) {
      temp = temp -> next;
    }
    temp -> next = new Node<T>(value);
  }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> *newNode = new Node<T>(value);
  newNode -> next = nullptr;
  if (j == 0) {
    insertStart(value);
  }
  else {
    Node<T> *temp = start;
    while (--j > 0) {
      temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
  }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node<T> *temp = start;
  start = temp -> next;
  delete temp;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> *temp = start;
  while (temp -> next != nullptr) {
    temp = temp -> next;
  }
  delete temp -> next;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> *temp = start;
  int i = 0;
  while (temp -> next != nullptr && i != j) {
    i++;
    if (i == j) {
      delete temp -> next;
      i++; //Keeps loop moving
    }
    else {
      temp = temp -> next;
    }
  }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  if (empty()) {
    return T();
  }
  else {
    return start -> value;
  }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  Node<T> *temp = start;
  while (temp -> next != nullptr) {
    temp = temp -> next;
  }
  return temp -> next -> value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> *temp = start;
  while (--j > 0) {
    temp = temp -> next;
  }
  return temp;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> *temp = start;
  Node<T> *value = nullptr;
  int i = 0;
  bool found = false;
  while (temp -> next != nullptr && !found) {
    if (temp -> next == key) {
      value = temp -> next;
      found = true;
    }
    else {
      temp = temp -> next;
    }
    i++;
  }
  return i;
}