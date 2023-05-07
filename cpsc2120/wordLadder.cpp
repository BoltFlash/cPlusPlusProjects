/*
    Keenan Grant
    CPSC 2120: 002
    12/13/22
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

//Implement breadth-first search, refer to Lab 10

unordered_map<string, bool> visited;
unordered_map<string, string> pred;
unordered_map<string, int> dist;
unordered_map<string, vector<string>> nbrs;

//Builds the graph
void build_graph() {
  //Adds the words to the V vector
  fstream file("wordlist05.txt");
  string word;
  while (file >> word) {
    V.push_back(word);
  }

  //Loops through the vector
  for (int i = 0; i < V.size(); i++) {
    //Loops through the letters of the current word of the vector loop
    for (int j = 0; j < V[i].length(); j++) {
      //Loops through the alphabet to begin word comparisons
      for (int k = 'a'; k <= 'z'; k++) {
        //The creation of the graph
        if (k != V[i].at(j)) {
          string theWord = V[i];
          theWord.at(j) = k;
          nbrs[V[i]].push_back(theWord);
        }
      }
    }
  }
}

//Recursive function that returns the shortest number of steps for the five letter word
int shortestSteps(string s, string t, vector<string> &p) {
  int steps = 0;
  //Returns 0 if the path does not exist
  if (pred.find(t) == pred.end()) {
    return 0;
  }
  //Adds to the path vector if the word ladder succeeds
  if (s.compare(t) != 0) {
    steps = shortestSteps(s, pred[t], p) + 1;
    p.push_back(t);
    return steps;
  }
  //Base case to end recursion
  else {
    p.push_back(t);
    return 0;
  }
}

//Breadth-first search
void wordLadder(string s, string t, int &steps, vector<string> &p) {
  //Implement this function

  build_graph();
  queue<string> to_visit;
	to_visit.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!to_visit.empty()) {
		string curnode = to_visit.front();
		to_visit.pop();
		for (string n : nbrs[curnode])
			if (!visited[n]) {
				pred[n] = curnode;
				dist[n] = 1 + dist[curnode];
				visited[n] = true;
				to_visit.push(n);
			}
	}

	steps = shortestSteps(s, t, p);
}

// int main(void)
// {
//   int steps = 0;
//   string s, t;
//   vector<string> path;
  
//   cout << "Source: ";
//   cin >> s;

//   cout << "Target: ";
//   cin >> t;

//   wordLadder(s, t, steps, path);

//   if (steps == 0)
//   {
//       cout << "No path!\n";
//   }
//   else
//   {
//       cout << "Steps: " << steps << "\n\n";
//       for (int i=0; i<path.size(); i++)
//       {
//           cout << path[i] << endl;
//       }
//   }
//   return 0;
// }