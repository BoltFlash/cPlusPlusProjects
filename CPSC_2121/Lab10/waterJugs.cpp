/*
 * Keenan Grant
 * 12/5/22
 * 003
 * Lab 10: Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph(void) {
  //Implement this function

  state current_state = make_pair(0,0);
  state result = make_pair(3, 4);

  //Loop that alters the jugs' water contents until the problem is solved
  while (current_state != result) {
    state next;

    //actions[0]: Fill A
    next = make_pair(3, current_state.second);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[0];
    }

    //actions[1]: Fill B
    next = make_pair(current_state.first, 4);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[1];
    }

    //actions[2]: Empty A
    next = make_pair(0, current_state.second);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[2];
    }

    //actions[3]: Empty B
    next = make_pair(current_state.first, 0);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[3];
    }

    //actions[4]: Pour A -> B
    int A2 = current_state.first;
    int B2 = current_state.second;
    while (A2 > 0 && B2 < 4) {
      A2--;
      B2++;
    }
    next = make_pair(A2, B2);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[4];
    }

    //actions[5]: Pour B -> A
    A2 = current_state.first;
    B2 = current_state.second;
    while (A2 < 3 && B2 > 0) {
      A2++;
      B2--;
    }
    next = make_pair(A2, B2);
    if (next != current_state) {
      nbrs[current_state].push_back(next);
      edge_label[make_pair(current_state, next)] = actions[5];
    }

    //Changing the current_state
    if (current_state.first == 3) {
      current_state = make_pair(0, current_state.second + 1);
    }
    else {
      current_state = make_pair(current_state.first + 1, current_state.second);
    }
  }
}

// int main(void)
// {
//   build_graph();

//   state start = make_pair(0,0);
  
//   for (int i=0; i<5; i++)
//     nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
//   search (start);
//   if (visited[make_pair(-1,-1)]) 
//     print_path (start, pred[make_pair(-1,-1)]);
//   else
//     cout << "No path!\n";
  
//   return 0;
// }