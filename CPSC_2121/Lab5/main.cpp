/*
 * Keenan Grant
 * 10/18/22
 * 003
 * Lab 5: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
// int main()
// {
//     Stringset wordlist;
//     loadStringset(wordlist, "wordlist02.txt");
//     testStringset(wordlist);
//     return 0;
// }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
//Loads a stringset from a text file
void loadStringset(Stringset& words, string filename) {
    //Implement this function

    fstream file(filename);
    string word;

    while (getline(file, word)) {
        words.insert(word);
    }
}

//Checks if there are similar words in a stringset compared to a word
vector<string> spellcheck(const Stringset& words, string word) {
    //Implement this function
    string comparison = word;
    vector<string> similarWords;

    //Replaces each character of the word with each character of the alphabet
    for (int i = 0; i < word.length(); i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            comparison.replace(i, 1, 1, j);
            if (words.find(comparison) && word != comparison) {
                similarWords.push_back(comparison);
            }
            comparison = word;
        }
    }

    return similarWords;
}