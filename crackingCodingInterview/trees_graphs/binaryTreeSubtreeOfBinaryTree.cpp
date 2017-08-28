#include <iostream>
#include <iomanip>
using namespace std;
 
struct Node
{
  struct Node *left, *right;
  int key;
};

Node* newNode(int key)
{
  Node *temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

void displayTree(Node *root, int ind)
{
  if(NULL == root)  return;

  displayTree(root->right, ind + 4);
  cout << setw(ind) << root->key << endl;
  displayTree(root->left, ind + 4);
}

bool areIdentical(Node *r1, Node *r2)
{
  if(! r1 && ! r2) return true;

  if(! r1 || ! r2) return false;
  
  return r1->key == r2->key &&
         areIdentical(r1->left, r2->left) &&
         areIdentical(r1->right, r2->right);
}

bool isSubtree(Node *T, Node *S)
{
  if(! S) return true;

  if(! T) return false;

  if(areIdentical(T, S))
    return true;

  return isSubtree(T->left, S) || 
         isSubtree(T->right, S);

}

int main()
{
  Node *T               = newNode(26);
  T->right              = newNode(3);
  T->right->right       = newNode(3);
  T->left               = newNode(10);
  T->left->left         = newNode(4);
  T->left->left->right  = newNode(30);
  T->left->right        = newNode(6);

  Node *S           = newNode(10);
  S->right          = newNode(6);
  S->left           = newNode(4);
  S->left->right    = newNode(30);

  displayTree(T, 0); cout << endl << endl;
  displayTree(S, 0);

  if (isSubtree(T, S))
    cout << "Tree 2 is subtree of Tree 1" << endl;
  else
    cout << "Tree 2 is not a subtree of Tree 1" << endl;

  return 0;
}
