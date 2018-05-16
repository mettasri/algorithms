#include <iostream>
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

//  printVector(lVec);
//  cout << setw(3) << vec[mid] << "  mid" << endl;
//  printVector(rVec);
//  cout << "--------------------------" << endl;

  Tree *pNode = new Tree(vec[mid]);
  pNode->pLeft = createTreeFromArray(lVec);
  pNode->pRight = createTreeFromArray(rVec);

  return pNode;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
  Tree *pRoot = createTreeFromArray(vec);
  displayTree(pRoot, 1);

  return 0;
}
