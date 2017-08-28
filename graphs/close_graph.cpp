#include <iostream>
#include <set>
#include <map>
using namespace std;


typedef struct graph_s
{
  int data;
  struct graph_s *neigh[4];
} Graph;


Graph* getGraphNode(int val) 
{
  Graph *pGraphNode = new Graph();  
  pGraphNode->data = val;
  for(int i = 0; i < 4; i++)
    pGraphNode->neigh[i] = NULL;
  return pGraphNode;
}

void displayGraph(Graph *pSt, set<Graph*> &set)
{
  if(!pSt)
    return;

  if(set.find(pSt) != set.end())
    return;

  set.insert(pSt);
  cout << pSt->data << endl;
  for(int i = 0; i < 4; i++)
  {
    displayGraph(pSt->neigh[i], set);
  }
}

void createMap(Graph *p1, map<Graph*, Graph*> &myMap)
{
  if(!p1)
    return;

  if(myMap.find(p1) != myMap.end())
    return;

  myMap.insert(pair<Graph*, Graph*>(p1, getGraphNode(p1->data)));

  for(int i = 0; i < 4; i++)
  {
    createMap(p1->neigh[i], myMap);
  }
}

void setNeighbors(Graph *p1, map<Graph*, Graph*> &myMap)
{
  map<Graph*, Graph*>::iterator it1, it2;

  for(it1 = myMap.begin(); it1 != myMap.end(); ++it1)
  {
//    cout << it1->first->data << ", " << it1->second->data << endl;
    for(int i = 0; i < 4; i++)
    {
      if(it1->first->neigh[i])
      {
        it2 = myMap.find(it1->first->neigh[i]);
        it1->second->neigh[i] = it2->second;
        cout << it1->second->data << "[" << i << "] = " << it2->second->data << endl;
      }
    }
  }

}

Graph* cloneGraph(Graph *p1)
{
  map<Graph*, Graph*> myMap;
  map<Graph*, Graph*>::iterator it;
  
  createMap(p1, myMap);
  for(it = myMap.begin(); it != myMap.end(); ++it)
  {
    cout << it->first->data << ", " << it->second->data << endl;
  }

  setNeighbors(p1, myMap);

  it = myMap.find(p1);
  return it->second;
}

int main()
{
  Graph *pStart1, *pStart2, *p0, *p1, *p2, *p3;

  p0 = getGraphNode(0);
  p1 = getGraphNode(1);
  p2 = getGraphNode(2);
  p3 = getGraphNode(3);

  p0->neigh[0] = p3;
  p0->neigh[1] = p2;
  p0->neigh[2] = p1;

  p1->neigh[0] = p0;
  p1->neigh[1] = p3;
  p1->neigh[2] = p2;

  p2->neigh[0] = p0;
  p2->neigh[1] = p1;

  p3->neigh[0] = p0;
  p3->neigh[1] = p1;

  pStart1 = p0;

  set<Graph*> mySet1;
  cout << "List1 " << endl;
  displayGraph(pStart1, mySet1);
  cout << endl;

  pStart2 = NULL;
  pStart2 = cloneGraph(pStart1);

  set<Graph*> mySet2;
  cout << "List2 " << endl;
  displayGraph(pStart2, mySet2);
  cout << endl;
}
