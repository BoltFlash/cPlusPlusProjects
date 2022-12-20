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
#include <bitset>
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i) { return (x>>i) & 1; }
const int wolf=0, goat=1, cabbage=2, me=3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from curnode)
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

string state_string(state s)
{
  string items[4] = { "wolf", "goat", "cabbage", "you" }, result = "";
  for (int i=0; i<4; i++)
    if (!bit(s, i)) result += items[i] + " ";
  result += " |river| ";
  for (int i=0; i<4; i++)
    if (bit(s, i)) result += items[i] + " ";
  return result;
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  } else {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}

string neighbor_label(int s, int t)
{
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross;
  if (bit(s,me) == bit(t,me)) return "";  // must cross river
  int cross_with = 0;
  for (int i=0; i<3; i++) {
    if (bit(s,i) != bit(t,i) && bit(s,i)==bit(s,me)) { cross_with++; which_cross = items[i]; }
    if (bit(s,i) != bit(t,i) && bit(s,i)!=bit(s,me)) return "";
  }
  if (cross_with > 1) return "";
  if (cross_with == 0) return "Cross alone";
  else return "Cross with " + which_cross;
}

//Function that tests if an entity could be taken across
bool noComp(bitset<4> test) {
  //Test if me is with the wolf and goat to avoid complication
  if (test[wolf] == test[goat]) {
    if (test[me] == test[wolf] && test[me] == test[goat]) {
      return true;
    }
  }
  //Test if me is with the goat and cabbage to avoid complication
  else if (test[goat] == test[cabbage]) {
    if (test[me] == test[goat] && test[me] == test[cabbage]) {
      return true;
    }
  }
  else {
    return true;
  }
  return false;
}

void build_graph(void) {
  //Implement this function

  //Bitset data structures to represent the positions of each entity in the order of wolf, goat, cabbage, me (right to left)
  bitset<4> current_state;
  bitset<4> result("1111");

  //Loop that represents each crossing of the river
  while (current_state != result) {
    //Loop to test each entity
    for (int i = 0; i < 4; i++) {
      //Tests if me is with the other entity being moved to the other side so complications will not occur
      if (current_state[me] == current_state[i]) {
        bitset<4> next = current_state;

        //Moves me and the i entity across the river
        next[me].flip();
        if (i != me) {
          next[i].flip();
        }

        //Checks if the move across the river was valid without any complications before adding it to the edge label
        if (noComp(next)) {
          int s = current_state.to_ulong();
          int t = next.to_ulong();
          nbrs[s].push_back(t);
          edge_label[make_pair(s, t)] = neighbor_label(s, t);
        }
      }
    }

    current_state = current_state.to_ulong() + 1;
  }
}

// int main(void)
// {
//   build_graph();

//   state start = 0, end = 15;
  
//   search(start);
//   if (visited[end])
//     print_path (start, end);
//   else
//     cout << "No path!\n";
  
//   return 0;
// }