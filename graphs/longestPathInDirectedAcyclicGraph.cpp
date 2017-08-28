#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <iomanip>
#include <limits.h>
using namespace std;

class ListAdjNode
{
  public:
    int node;
    int weight;

    ListAdjNode() { }
    ListAdjNode(int n, int w) : node(n), weight(w) { }
};

class Graph
{
  int v;
  list<ListAdjNode *> *pList;
 
 public:
  Graph(int);
  void addEdge(int, int, int);
  void printGraph();
  void longestPath(int);
  void topologicalSorting(int i, stack<int> &sk, vector<bool> &lookUp);
};

Graph::Graph(int v)
{
  this->v = v;
  pList = new list<ListAdjNode *>[v];
}

void Graph::addEdge(int src, int dst, int weight)
{
  ListAdjNode *listNode= new ListAdjNode(dst, weight);
  pList[src].push_back(listNode);
}

void Graph::printGraph()
{
  for(int i = 0; i < this->v; i++)
  {
    list<ListAdjNode *>::iterator it;
    cout << "head[" << i << "]";
    for(it = pList[i].begin(); it != pList[i].end();it++)
    {
      cout << " -> " << (*it)->node << "/" << (*it)->weight;
    }
    cout << endl;
  }
}

void Graph::topologicalSorting(int i, stack<int> &sk, vector<bool> &lookUp)  {
  lookUp[i] = true;

  for(list<ListAdjNode *>::iterator it = pList[i].begin(); it != pList[i].end(); ++it) {
    if(! lookUp[(*it)->node]) {
      topologicalSorting((*it)->node, sk, lookUp);
    }
  }

  sk.push(i);
}

void Graph::longestPath(int node) {
  stack<int> sk;
  vector<bool> lookUp(v, false);
  vector<int> distance(v, INT_MIN);

  for(int i = 0; i < v; i++) {
    if(! lookUp[i])  {
      topologicalSorting(i, sk, lookUp);
    }
  }

  distance[node] = 0;
  int n;
  while(! sk.empty()) {
//    cout << setw(3) << sk.top();
    n = sk.top();
    sk.pop();

    for(list<ListAdjNode *>::iterator it = pList[n].begin(); it != pList[n].end(); ++it) {
      if(distance[(*it)->node] < (distance[n] + (*it)->weight))  {
        distance[(*it)->node] = distance[n] + (*it)->weight;
      }
    }
  }

  for(int i = 0; i < v; i++) {
    cout << setw(4) << distance[i];
  }
  cout << endl;
}

int main()
{
  Graph g(6);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(3, 5, 1);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  g.printGraph();

  g.longestPath(1);

  return 0;
}

