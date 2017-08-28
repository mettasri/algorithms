#include<iostream>
#include<list>
#include<limits.h>
#include<vector>
#include<iomanip>
using namespace std;

// WHITE 0  Vertex is not processed yet. Initially all vertices are WHITE.
// GRAY  1  Vertex is being processed but not all its descendants
// BLACK 2  Vertex and all its descendants are processed.

enum Color {WHITE, GRAY, BLACK};

class Graph
{
  int V;
  list<int> *adj;    
  bool DFSColors(int v, vector<Color> &visited);
 public:
  Graph(int V);   
  void addEdge(int v, int w);   
  bool isCyclic();    
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); 
}

bool Graph::DFSColors(int v, vector<Color> &visited)
{
  if (visited[v] == GRAY)  {
    cout << "     Loop ";
    return true;
  }
  visited[v] = GRAY;

  for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (visited[*i] != BLACK) {
      if(DFSColors(*i, visited))  {
        cout << setw(3) << *i;
        return true;
      }
    }
  }

  visited[v] = BLACK;
  return false;
}

bool Graph::isCyclic()
{
  vector<Color>visited(V, WHITE);

  for(int i = 0; i < V; i++)
  {
    if(WHITE == visited[i]) {
      if (DFSColors(i, visited)) {
        cout << endl;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  Graph g1(4);
  g1.addEdge(0, 1);
  g1.addEdge(1, 2);
  g1.addEdge(2, 0);
  g1.addEdge(2, 3);
  g1.addEdge(3, 3);
  true == g1.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  cout << "-------------------------------" << endl;
  Graph g2(4);
  g2.addEdge(0, 1);
  g2.addEdge(2, 0);
  g2.addEdge(2, 3);
  g2.addEdge(3, 3);
  true == g2.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  cout << "-------------------------------" << endl;
  Graph g3(5);
  g3.addEdge(0, 1);
  g3.addEdge(1, 2);
  g3.addEdge(2, 3);
  g3.addEdge(3, 4);
  g3.addEdge(4, 1);
  true == g3.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [no cycle]" << endl;

  cout << "-------------------------------" << endl;
  Graph g4(3);
  g4.addEdge(0, 1);
  g4.addEdge(1, 2);
  g4.addEdge(0, 2);
  false == g4.isCyclic() ? cout << "PASS [No cycle]" << endl : cout << "FAIL [Cycle Present]" << endl;

  cout << "-------------------------------" << endl;
  Graph g5(5);
  g5.addEdge(0, 1);
  g5.addEdge(0, 2);
  g5.addEdge(2, 3);
  g5.addEdge(3, 4);
  g5.addEdge(4, 2);
  true == g5.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [No Cycle]" << endl; 

  cout << "-------------------------------" << endl;
  Graph g6(6);
  g6.addEdge(1, 2);
  g6.addEdge(3, 4);
  g6.addEdge(4, 5);
  g6.addEdge(5, 3);
  true == g6.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [No Cycle]" << endl; 

  cout << "-------------------------------" << endl;
  Graph g7(4);
  false == g7.isCyclic() ? cout << "PASS [No Cycle]" << endl : cout << "FAIL [Cycle Present]" << endl; 

  cout << "-------------------------------" << endl;
  Graph g8(8);
  g8.addEdge(0, 1);
  g8.addEdge(0, 2);
  g8.addEdge(1, 3);
  g8.addEdge(1, 4);
  g8.addEdge(5, 6);
  g8.addEdge(5, 7);
  false == g8.isCyclic() ? cout << "PASS [No Cycle]" << endl : cout << "FAIL [Cycle Present]" << endl; 

  cout << "-------------------------------" << endl;
  Graph g9(9);
  g9.addEdge(3, 5);

  g9.addEdge(5, 4);
  g9.addEdge(4, 6);
  g9.addEdge(6, 8);

  g9.addEdge(5, 2);
  g9.addEdge(2, 6);
  g9.addEdge(6, 8);

  g9.addEdge(3, 1);
  g9.addEdge(1, 7);
  g9.addEdge(7, 2);
  g9.addEdge(7, 8);
  false == g9.isCyclic() ? cout << "PASS [No Cycle]" << endl : cout << "FAIL [Cycle Present]" << endl; 

  cout << "-------------------------------" << endl;
  Graph g10(6);
  g10.addEdge(0, 1);
  g10.addEdge(0, 2);
  g10.addEdge(1, 2);
  g10.addEdge(3, 0);
  g10.addEdge(3, 2);
  g10.addEdge(3, 5);
  g10.addEdge(4, 3);
  g10.addEdge(5, 2);
  g10.addEdge(5, 4);
  true == g10.isCyclic() ? cout << "PASS [Cycle Present]" << endl : cout << "FAIL [No Cycle]" << endl; 

  return 0;
}
