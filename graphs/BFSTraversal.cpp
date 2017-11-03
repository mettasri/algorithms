#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
using namespace std;

class Graph {
  int v;
  list<int> *adj;
 
 public:
  Graph(int);
  void addEdge(int, int);
  void printGraph();
  void breadthFirstTraversal(int node);
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int src, int dst) {
  adj[src].push_back(dst);
}

void Graph::printGraph() {
  for(int i = 0; i < this->v; i++) {
    list<int>::iterator it;
    cout << "[" << i << "]";
    for(it = adj[i].begin(); it != adj[i].end();it++) {
      cout << " -> " << *it;
    }
    cout << endl;
  }
}

void Graph::breadthFirstTraversal(int node) {
  int i;
  vector<int> lookUp(4, 0);
  queue<int> q;

  q.push(node);
  lookUp[node] = true;

  list<int>::iterator it;
  while(! q.empty()) {
    i = q.front();
    q.pop();
    cout << setw(2) << i;

    for(it = adj[i].begin(); it != adj[i].end(); it++) {
      if(! lookUp[*it])  {
        lookUp[*it] = true;
        q.push(*it);
      }
    }
  }
  cout << endl;
}

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.printGraph();
  g.breadthFirstTraversal(2);

  return 0;
}

