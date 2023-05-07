/*
 * Keenan Grant
 * 10/27/22
 * Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

// int main()
// {
//     vector<string> words;
//     vector<string> anagrams;
//     string inputWord;
//     words=loadWordlist("wordlist.txt");
//     cout << "Find single-word anagrams for the following word: ";
//     cin >> inputWord;
//     anagrams = anagram(inputWord, words);
//     for (int i=0; i<anagrams.size(); i++)
//     {
//         cout << anagrams[i] << endl;
//     }
//     return 0;
// }

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
//Finds the anagram(s) of a word and returns a vector of them
vector<string> anagram(string word, vector<string> wordlist) {
    vector<string> theAnagrams;

    for (int i = 0; i < wordlist.size(); i++) {
        bool isAnagram = true;
        unordered_map<char, int> map;
        if (word.length() != wordlist[i].length()) {
            isAnagram = false;
        }

        if (isAnagram) {
            for (int j = 0; j < word.length(); j++) {
                map[word[j]]++;
            }
            for (int j = 0; j < wordlist[i].size(); j++) {
                if (map.find(wordlist[i][j]) != map.end()) {
                    map[wordlist[i][j]]--;
                    if (map[wordlist[i][j]] == 0) {
                        map.erase(wordlist[i][j]);
                    }
                }
            }
            if (map.empty()) {
                theAnagrams.push_back(wordlist[i]);
            }
        }
    }
    return theAnagrams;
}