#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <memory>

// Graph reprasentation in Edge list
class Edge {
 public:
  Edge(int s, int d, int w)
      : source(s), destination(d), weight(w) {}
  ~Edge() {
    //std::cout << "Edge deleted" << std::endl;
  }

  void Display() {
    std::cout << std::setw(3) << weight << std::setw(3) << source
              << std::setw(3) << destination << std::endl;
  }
  const int GetSource()       { return source; }
  const int GetDestination()  { return destination; }
  const int GetWeight() const { return weight; }

 private:
  int source;
  int destination;
  int weight;
};

class Graph {
 public:
  Graph(int v) : V(v) {}
  
  ~Graph() {
    //std::cout << "Graph deleted" << std::endl;
  }

  void AddEdge(int s, int d, int w) {
    std::shared_ptr<Edge> edge = std::make_shared<Edge>(s, d, w);
    edges.push_back(edge);
  }

  void Display() {
    std::cout << std::setw(3) << "w" << std::setw(3) << "s"
              << std::setw(3) << "d" << std::endl;
    //for (auto edge : edges) { // implicit deleted copy-constructor
    for (const std::shared_ptr<Edge>& edge : edges) {
      edge->Display();
    }
  }

  void Display(std::vector<int>& parent) {
    for (auto v : parent) {
      std::cout << std::setw(3)<< v;
    }
    std::cout << std::endl;
    for (int i = 0; i < parent.size(); ++i) {
      std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
  }
  
  bool DetectCycle() {
    std::vector<int> vertex_parents(V, -1);
    std::vector<int> vertex_rank(V, 0);
    for (const std::shared_ptr<Edge>& edge : edges) {
      if (DetectCycleUnionFindRank(vertex_parents, vertex_rank, edge)) {
        return true;
      }
    }
    return false;
  }

  /*bool DetectCycle() {
    std::vector<int> vertex_parents(V, -1);
    for (const std::shared_ptr<Edge>& edge : edges) {
      if (DetectCycleUnionFind(vertex_parents, edge))
        return true;
    }
    return false;
  }*/

  std::unique_ptr<std::vector<std::shared_ptr<Edge>>> ConstructMst() {
    edges.sort([](const std::shared_ptr<Edge>& e1,
                  const std::shared_ptr<Edge>& e2) -> bool {
                 return (e1->GetWeight() <= e2->GetWeight());
               });
  
    std::unique_ptr<std::vector<std::shared_ptr<Edge>>> mst_edges(
        new std::vector<std::shared_ptr<Edge>>);
    std::vector<int> vertex_parents(V, -1);
    std::vector<int> vertex_rank(V, 0);
    for (const std::shared_ptr<Edge>& edge : edges) {
      if (!DetectCycleUnionFindRank(vertex_parents, vertex_rank, edge)) {
      //if (!DetectCycleUnionFind(vertex_parents, edge)) {
        mst_edges->push_back(edge);
        if (mst_edges->size() > (V - 1)) {
          break;
        }
      }
    }
    return std::move(mst_edges);
  }

 private:
  int V;
  std::list<std::shared_ptr<Edge>> edges;

  // return top most parent
  int FindParent(std::vector<int>& parent, int vertex) {
    if (parent[vertex] == -1) {
      return vertex;
    }
    return FindParent(parent, parent[vertex]);
  }
  
  void Union(std::vector<int>& parent, int vertex1, int vertex2) {
    parent[vertex1] = vertex2;
  }

  void UnionByRank(std::vector<int>& parent, std::vector<int>& rank,
                   int vertex1, int vertex2) {
    if (rank[vertex1] < rank[vertex2]) {
      parent[vertex1] = vertex2;
    } else if (rank[vertex1] > rank[vertex2]) {
      parent[vertex2] = vertex1;
    } else {
      parent[vertex1] = vertex2;
      rank[vertex2]++;
    }
  }
  
  bool DetectCycleUnionFindRank(std::vector<int>& parents,
                                std::vector<int>& rank,
                                const std::shared_ptr<Edge>& edge) {
    auto source_parent = FindParent(parents, edge->GetSource());
    auto destination_parent = FindParent(parents,
                                         edge->GetDestination());
    if (source_parent == destination_parent) {
      //Display(parents);
      //edge->Display();
      return true;
    }
    UnionByRank(parents, rank, source_parent, destination_parent);
    return false;
  }
  
  bool DetectCycleUnionFind(std::vector<int>& parents,
                            const std::shared_ptr<Edge>& edge) {
    auto source_parent = FindParent(parents, edge->GetSource());
    auto destination_parent = FindParent(parents,
                                         edge->GetDestination());
    if (source_parent == destination_parent) {
      //Display(parents);
      //edge->Display();
      return true;
    }
    Union(parents, source_parent, destination_parent);
    return false;
  }
};

int main() {
  Graph g(9);
  g.AddEdge(8, 6, 6);
  g.AddEdge(5, 4, 10);
  g.AddEdge(6, 5, 2);
  g.AddEdge(7, 6, 1);
  g.AddEdge(0, 1, 4);
  g.AddEdge(2, 3, 7);
  g.AddEdge(2, 5, 4);
  g.AddEdge(8, 2, 2);
  g.AddEdge(3, 4, 9);
  g.AddEdge(1, 2, 8);
  g.AddEdge(7, 8, 7);
  g.AddEdge(3, 5, 14);
  g.AddEdge(0, 7, 8);
  g.AddEdge(1, 7, 11);
  
  //g.Display();

  auto result = g.DetectCycle();
  std::cout << "Cycle Present: ";
  result ? std::cout << "Yes\n" : std::cout << "No\n";

  std::unique_ptr<std::vector<std::shared_ptr<Edge>>> mst_edges = g.ConstructMst();
  for (const std::shared_ptr<Edge>& edge : *mst_edges) {
    edge->Display();
  }

  return 0;
}
