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
  void depthFirstTraversal(int node, vector<int> &lookUp);
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
    cout << "head[" << i << "]";
    for(it = adj[i].begin(); it != adj[i].end();it++) {
      cout << " -> " << *it;
    }
    cout << endl;
  }
}

void Graph::depthFirstTraversal(int i, vector<int> &lookUp) {
  if(lookUp[i])  {
    return;
  }

  cout << setw(3) << i;
  lookUp[i] = true;
  for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
    depthFirstTraversal(*it, lookUp);
  }
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

  vector<int> lookUp(4, 0);
  //for (int v = 0; v < 4; ++v) {
  //  g.depthFirstTraversal(v, lookUp);
  //}
  g.depthFirstTraversal(2, lookUp);
  cout << endl;

  return 0;
}
