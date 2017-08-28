#include <iostream>
#include <iomanip>
#include <climits>
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

  displayTree(root->right, ind + 3);
  cout << setw(ind) << root->key << endl;
  displayTree(root->left, ind + 3);
}
 
bool isLeftDataGreaterThanRightData(Node *pRoot)
{
  if(! pRoot) return true;
  
  int left  = pRoot->left  ? pRoot->left->key  : INT_MAX;
  int right = pRoot->right ? pRoot->right->key : INT_MIN;

  return (left > right && 
          isLeftDataGreaterThanRightData(pRoot->left) &&
          isLeftDataGreaterThanRightData(pRoot->right));
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(5);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(6);

    displayTree(root, 0);

    true == isLeftDataGreaterThanRightData(root) ? cout << "PASS" << endl : cout << "FAIL" << endl;

    Node * root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(7);
    root1->right->right = newNode(6);

    displayTree(root1, 0);

    true == isLeftDataGreaterThanRightData(root1) ? cout << "FAIL" << endl : cout << "PASS" << endl;

    Node * root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
//    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->right->left = newNode(7);
    root2->right->right = newNode(6);

    displayTree(root2, 0);

    true == isLeftDataGreaterThanRightData(root2) ? cout << "PASS" << endl : cout << "FAIL" << endl;

    return 0;
}
