#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

class Graph
{
  int v;
  list<int> *pList;
 
 public:
  Graph() {}
  Graph(int);
  void addEdge(int, int);
  void printGraph();
  void DFS(int i, vector<bool> &lookUp);
  int motherVertex();
  void printSCCs();
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

void Graph::DFS(int i,  vector<bool> &lookUp) {
  lookUp[i] = true;
  for(list<int>::iterator it = pList[i].begin(); it != pList[i].end(); it++) {
    if(! lookUp[*it])  {
      DFS(*it, lookUp);
    }
  }
}

int Graph::motherVertex() {
  vector<bool> lookUp(v, false);
  int motherVertex;
  // find the last vertex in DFS, that may be a mother vertex
  for(int i = 0; i < v; ++i) {
    if(! lookUp[i]) {
      DFS(i, lookUp);
      motherVertex = i;
    }
  }

  // check if this last vertex is a mother vertex
  lookUp.assign(v, false);
  DFS(motherVertex, lookUp);

  for(int i = 0; i < v; ++i) {
    if(!lookUp[i]) {
      return (-1);
    }
  }
  return motherVertex;
}

int main()
{
  Graph g1(5);
  g1.addEdge(0, 2);
  g1.addEdge(0, 3);
  g1.addEdge(1, 0);
  g1.addEdge(2, 1);
  g1.addEdge(3, 4);

  g1.printGraph();
  cout << endl;
  cout << "Mother Vertex: " << g1.motherVertex() << endl << endl;

  Graph g2(7);
  g2.addEdge(0, 1);
  g2.addEdge(0, 2);
  g2.addEdge(1, 3);
  g2.addEdge(4, 1);
  g2.addEdge(5, 2);
  g2.addEdge(5, 6);
  g2.addEdge(6, 0);
  g2.addEdge(6, 4);

  g2.printGraph();
  cout << endl;
  cout << "Mother Vertex: " << g2.motherVertex() << endl;

  return 0;
}
