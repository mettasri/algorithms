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
  void depthFirstTraversal(int node, vector<bool> &lookUp);
  void addNeighborsByDFS(Graph *g, int i, vector<bool> &lookUp);
  Graph* cloneDirectedGraph();
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
  cout << endl;
}

void Graph::addNeighborsByDFS(Graph *g, int i, vector<bool> &lookUp)
{
  lookUp[i] = true;
//  cout << i << " true" << endl;
  for(list<int>::iterator it = pList[i].begin(); it != pList[i].end(); it++)  {
    g->addEdge(i, *it);
    if(! lookUp[*it]) {
//      cout << "added link: " << i << " " << *it << endl;
      addNeighborsByDFS(g, *it, lookUp);
    }
  }
}

Graph* Graph::cloneDirectedGraph()
{
  Graph *newG = new Graph(v);
  vector<bool> lookUp(v, false);
  
  for(int i = 0; i < this->v; i++)  {
    if(! lookUp[i])  {
      addNeighborsByDFS(newG, i, lookUp);
    }
  }
  return newG;
}

int main()
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 1);
  g.addEdge(3, 4);

  Graph *newG = g.cloneDirectedGraph();
  g.printGraph();
  newG->printGraph();

  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 3);
  g1.addEdge(1, 2);
  g1.addEdge(3, 4);

  Graph *newG1 = g1.cloneDirectedGraph();
  g1.printGraph();
  newG1->printGraph();

  return 0;
}

