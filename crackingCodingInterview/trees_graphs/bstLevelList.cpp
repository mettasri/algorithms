#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
using namespace std;

class Tree
{
  public:
    int data;
    Tree *pLeft;
    Tree *pRight;

    Tree(int val) {
      data = val;
      pLeft = NULL;
      pRight = NULL;
    }
};

void printVector(vector<int> &vec)
{
  for(int i = 0; i < vec.size(); i++)
    cout << setw(3) << vec[i];
  cout << endl;
}

void displayTree(Tree *pNode, int ind)
{
  if(! pNode) return;

  displayTree(pNode->pRight, ind + 3);
  cout << setw(ind) << pNode->data << endl;
  displayTree(pNode->pLeft, ind + 3);

  return;
}

Tree* createTreeFromArray(vector<int> &vec)
{
  if(! vec.size()) return NULL;

  int mid = vec.size()/2;
  vector<int> lVec(vec.begin(), vec.begin() + mid);
  vector<int> rVec(vec.begin() + mid + 1, vec.end());
  Tree *pNode = new Tree(vec[mid]);
  pNode->pLeft = createTreeFromArray(lVec);
  pNode->pRight = createTreeFromArray(rVec);

  return pNode;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

int height(Tree *pNode)
{
  if(! pNode) return 0;
  return 1 + max(height(pNode->pLeft), height(pNode->pRight));
}

void addNodesAtLevel(Tree *pNode, list<int> *levelList, int h)
{
  if(! pNode) return;
  addNodesAtLevel(pNode->pLeft,  levelList, h + 1);
  addNodesAtLevel(pNode->pRight, levelList, h + 1);
  levelList[h].push_back(pNode->data);
  return;
}

void createListAtLevelDFS(Tree *pRoot)
{
  int h = height(pRoot);
  cout << "Height of the tree: " << h << endl;
  list<int> *levelList = new list<int>[h];

  addNodesAtLevel(pRoot, levelList, 0);

  for(int i = 0; i < h; i++) {
    for(list<int>::iterator it = levelList[i].begin(); it != levelList[i].end(); ++it) {
      cout << setw(3) << *it;
    }
    cout << endl;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
  Tree *pRoot = createTreeFromArray(vec);
  displayTree(pRoot, 1);
  createListAtLevelDFS(pRoot);

  return 0;
}
