#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
using namespace std;

class Graph
{
  int v;
  list<int> *pEdges;
  int *pParent;
 
 public:
  Graph(int);
  void addEdge(int, int);
  void printGraph();
  void breadthFirstTraversal(int node);
  void unionOfEdges(int x, int y);
  int findParent(int i);
  bool detectCycle();
  void displayParent();
};

Graph::Graph(int v)
{
  this->v = v;
  pEdges  = new list<int>[v];
  pParent = new int[v];
  
  for(int i = 0; i < v; ++i) {
    pParent[i] = i;
  }
}

void Graph::addEdge(int src, int dst)
{
  pEdges[src].push_back(dst);
  pEdges[dst].push_back(src);
}

void Graph::printGraph()
{
  for(int i = 0; i < this->v; i++)
  {
    list<int>::iterator it;
    cout << "head[" << i << "]";
    for(it = pEdges[i].begin(); it != pEdges[i].end();it++)
    {
      cout << " -> " << *it;
    }
    cout << endl;
  }
}

int Graph::findParent(int i) {
  if(pParent[i] == i) 
    return i;
  return findParent(pParent[i]);
}

void Graph::unionOfEdges(int x, int y) {
  pParent[x] = y;
}

/* logic is wrong becuase the vertices are considered.
 * Edges needs to be considered to make it work
 */
bool Graph::detectCycle()  {
  for(int i = 0; i < this->v; ++i) {
    for(list<int>::iterator it = pEdges[i].begin(); it != pEdges[i].end(); ++it) {
      int x = findParent(i);
      int y = findParent(*it);

      if(x == y)
        return true;

      unionOfEdges(x, y);
    }
  }
  return false;
}

void Graph::displayParent() {
  for(int i = 0; i < v; i++)
    cout << setw(3) << pParent[i];
  cout << endl;
  for(int i = 0; i < v; i++)
    cout << setw(3) << i;
  cout << endl;
}

int main()
{
  Graph g(3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 0);

  g.printGraph();
  true == g.detectCycle() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;
  g.displayParent();

  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 3);
  g1.addEdge(1, 2);
  g1.addEdge(2, 0);
  g1.addEdge(3, 4);
  g1.printGraph();
  true == g1.detectCycle() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;
  g1.displayParent();

  return 0;
}

