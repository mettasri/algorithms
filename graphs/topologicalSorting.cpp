#include <iostream>
#include <vector>
#include <list>
#include <stack>
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
  void topologicalSorting(int i, stack<int> &sk, vector<int> &lookUp);
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
  cout << i << endl;

  for(list<int>::iterator it = pList[i].begin(); it != pList[i].end(); it++) {
    if(! lookUp[*it])  {
      depthFirstTraversal(*it, lookUp);
    }
  }
}

void Graph::topologicalSorting(int i, stack<int> &sk, vector<int> &lookUp)  {
  lookUp[i] = true;

  for(list<int>::iterator it = pList[i].begin(); it != pList[i].end(); it++) {
    if(! lookUp[*it])  {
      topologicalSorting(*it, sk, lookUp);
    }
  }
  sk.push(i);
}

int main()
{
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.printGraph();

  vector<int> lookUp(6, 0);
  stack<int> sk;

  g.depthFirstTraversal(5, lookUp);
  g.depthFirstTraversal(4, lookUp);

  lookUp.assign(6, 0);
  for(int i = 0; i < 6; i++)  {
    if(! lookUp[i])  {
      g.topologicalSorting(i, sk, lookUp);
    }
  }

  while(! sk.empty()) {
    cout << setw(3) << sk.top();
    sk.pop();
  }

  return 0;
}

