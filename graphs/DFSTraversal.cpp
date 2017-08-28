#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
using namespace std;

class Graph
{
  int v;
  list<int> *pList;
 
 public:
  Graph(int);
  void addEdge(int, int);
  void printGraph();
  void depthFirstTraversal(int node, vector<int> &lookUp);
};

Graph::Graph(int v)
{
  this->v = v;
  pList = new list<int>[v];
}

void Graph::addEdge(int src, int dst)
{
  pList[src].push_back(dst);
}

void Graph::printGraph()
{
  for(int i = 0; i < this->v; i++)
  {
    list<int>::iterator it;
    cout << "head[" << i << "]";
    for(it = pList[i].begin(); it != pList[i].end();it++)
    {
      cout << " -> " << *it;
    }
    cout << endl;
  }
}

void Graph::depthFirstTraversal(int i, vector<int> &lookUp) {
  lookUp[i] = true;
  cout << setw(3) << i;

  for(list<int>::iterator it = pList[i].begin(); it != pList[i].end(); it++) {
    if(! lookUp[*it])  {
      depthFirstTraversal(*it, lookUp);
    }
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
  g.depthFirstTraversal(2, lookUp);

  return 0;
}
