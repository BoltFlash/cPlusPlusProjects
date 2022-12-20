/*
 * Keenan Grant
 * 10/18/22
 * 003
 * Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <functional>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

//Inserts a word into the stringset if it is not already in it
void Stringset::insert(string word) {
    //Implement this function

    hash<string> hashing;
    string temp;

    if (!find(word)) {
        //Doubles the stringset size if it gets full and re-hashes all of the current words
        if (num_elems == size) {
            vector<list<string>> newTable(size * 2);
            for (int i = 0; i < size; i++) {
                for (list<string>::iterator j = table[i].begin(); j != table[i].end(); j++) {
                    temp = *j;
                    int element2 = hashing(temp) % (size * 2);
                    newTable[element2].push_back(temp);
                }
            }
            size *= 2;
            table = newTable;
        }

        //Inserts a word into the stringset
        int element = hashing(word) % size;
        table[element].push_back(word);
        num_elems++;
    }
}

//Finds if a word is in the stringset
bool Stringset::find(string word) const {
    //Implement this function

    bool target = false;
    hash<string> hashing;
    int element = hashing(word) % size;

    //Searches through the stringset to find a desired word
    for (list<string>::const_iterator j = table[element].begin(); j != table[element].end(); j++) {
        if (word == *j) {
            target = true;
        }
    }

    return target;
}

//Erases desired word
void Stringset::remove(string word) {
    //Implement this function

    hash<string> hashing;
    int element = hashing(word) % size;
    table[element].remove(word);
    num_elems--;
}