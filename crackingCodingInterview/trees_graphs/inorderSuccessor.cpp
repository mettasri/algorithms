#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Tree
{
  public:
    int data;
    Tree *pParent;
    Tree *pLeft;
    Tree *pRight;

    Tree(int val) {
      data = val;
      pParent = NULL;
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

  displayTree(pNode->pRight, ind + 4);
  int p = pNode->pParent ? pNode->pParent->data : -1;
  cout << setw(ind) << pNode->data <<"/" << p << endl;
  displayTree(pNode->pLeft, ind + 4);

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

void addLinkToParent(Tree *pNode, Tree *p)
{
  if(! pNode) return;

  addLinkToParent(pNode->pLeft, pNode);
  addLinkToParent(pNode->pRight, pNode);
  pNode->pParent = p;
  return;
}

Tree* leftMostChild(Tree *pNode)
{
  if(! pNode) return NULL;

  while(pNode->pLeft)
    pNode = pNode->pLeft;

  return pNode;
}

Tree* leftChildParent(Tree *pParent, Tree *pNode)
{
  if(! pParent) return NULL;
  if(pParent->pLeft == pNode) return pParent;

  return leftChildParent(pParent->pParent, pParent);
}

void inorderSuccessor(Tree *pNode, int key, int &suc)
{
  if(! pNode) return;

  Tree *temp;
  if(pNode->data == key)  {
    if(pNode->pRight) {
      temp = leftMostChild(pNode->pRight);
      suc = temp->data;
      return;
    }
  }
  if(key < pNode->data)  {
    suc = pNode->data;
    inorderSuccessor(pNode->pLeft,  key, suc);
  } else  {
    inorderSuccessor(pNode->pRight, key, suc);
  }
}

Tree* inorderSuccessorWithParentLink(Tree *pNode, int key)
{
  if(! pNode) return NULL;

  if(pNode->data == key)  {
    if(pNode->pRight) {
      return leftMostChild(pNode->pRight);
    } else {
      return leftChildParent(pNode->pParent, pNode);
    }
  }

  Tree *retNode;
  if(key < pNode->data)  {
    retNode = inorderSuccessorWithParentLink(pNode->pLeft,  key);
  } else  {
    retNode = inorderSuccessorWithParentLink(pNode->pRight, key);
  }
  return retNode;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
  
  Tree *pRoot = createTreeFromArray(vec);
  
  addLinkToParent(pRoot, NULL);
  
  displayTree(pRoot, 1);

  int suc = -1;
  for(int i = 0; i < sizeof(arr)/sizeof(int); i++)  {
    inorderSuccessor(pRoot, arr[i], suc);
    cout << setw(3) << arr[i] << setw(3) << suc << endl;
  }
  cout << endl;
  Tree *pSuc;
  for(int i = 0; i < sizeof(arr)/sizeof(int); i++)  {
    pSuc = inorderSuccessorWithParentLink(pRoot, arr[i]);
    suc = pSuc ? pSuc->data : -1;
    cout << setw(3) << arr[i] << setw(3) << suc << endl;
  }

  return 0;
}

