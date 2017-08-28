#include<iostream>
#include<list>
#include<limits.h>
#include<vector>
#include<iomanip>
using namespace std;

class Graph
{
  int V;
  list<int> *adj;    
  bool DFSUtil(int v, vector<bool> &visited, int parent);

  public:
  Graph(int V);   
  void addEdge(int v, int w);   
  bool detectCycleInUndirectedGraph();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); 
  adj[w].push_back(v); 
}

bool Graph::DFSUtil(int v, vector<bool> &visited, int parent)
{
  visited[v] = true;
//  cout << "v " << v << "/" << parent << endl;
  for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
    if((visited[*i]) && (*i != parent)) {
      cout << setw(3) << *i;
      return true;
    }
    if (! visited[*i]) {
      if(DFSUtil(*i, visited, v))  {
        cout << setw(3) << *i;
        return true;
      }
    }
  }

//  cout << "v " << v << ": " << visited[v] << endl;
  return false;
}

bool Graph::detectCycleInUndirectedGraph()
{
  int loopNode;
  vector<bool>visited(V, false);

  for(int i = 0; i < V; i++)
  {
    if(! visited[i]) {
      if(DFSUtil(i, visited, -1)) {
        cout << setw(3) << i << endl;
        return true;
      }
    }
  }
  return false;
}

int main()
{

  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 3);
  g1.addEdge(1, 2);
  g1.addEdge(2, 0);
  g1.addEdge(3, 4);
  true == g1.detectCycleInUndirectedGraph() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  Graph g2(6);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(1, 5);
  g2.addEdge(1, 3);
  g2.addEdge(5, 4);
  g2.addEdge(3, 4);
  true == g2.detectCycleInUndirectedGraph() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  Graph g3(5);
  g3.addEdge(0, 1);
  g3.addEdge(2, 3);
  g3.addEdge(2, 4);
  g3.addEdge(3, 4);
  true == g3.detectCycleInUndirectedGraph() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  Graph g4(5);
  g4.addEdge(2, 3);
  g4.addEdge(2, 4);
  false == g4.detectCycleInUndirectedGraph() ? cout << "PASS [no cycle]" << endl : cout << "FAIL [Cycle Present]" << endl;

  return 0;
}
