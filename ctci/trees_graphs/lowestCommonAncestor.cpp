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

int contains(struct Node* root, int n1, int n2)
{
  int ret = 0;

  if(! root) return ret;
  if(root->key == n1 || root->key == n2) 
    ret += 1;

  ret += contains(root->left, n1, n2);
  if(ret == 2)
    return ret;
  ret += contains(root->right, n1, n2);

  return ret;
}
 
struct Node *findLCA(struct Node* root, int n1, int n2)
{
  if(! root) return NULL;

  int leftPresentNodes = contains(root->left, n1, n2);
  if(leftPresentNodes == 2)  {
    if(root->left && (root->left->key == n1 || root->left->key == n2))
      return root->left;
    else
      return findLCA(root->left, n1, n2);
  } else if(leftPresentNodes == 1) {
    if(root->key == n1 || root->key == n2)
      return root;
  }


  int rightPresentNodes = contains(root->right, n1, n2);
  if(rightPresentNodes == 2)  {
    if(root->right && (root->right->key == n1 || root->right->key == n2))
      return root->right;
    else
      return findLCA(root->right, n1, n2);
  } else if(rightPresentNodes == 1) {
    if(root->key == n1 || root->key == n2)
      return root;
  }

  if(leftPresentNodes == 1 && rightPresentNodes == 1)
    return root;
  else
    return NULL;
}

void displayTree(Node *root, int ind)
{
  if(NULL == root)  return;

  displayTree(root->right, ind + 3);
  cout << setw(ind) << root->key << endl;
  displayTree(root->left, ind + 3);
}
 
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    displayTree(root, 0);

    2 == findLCA(root, 4, 5)->key ? cout << "PASS\n" : cout << "FAIL\n";
    1 == findLCA(root, 4, 6)->key ? cout << "PASS\n" : cout << "FAIL\n";
    1 == findLCA(root, 3, 4)->key ? cout << "PASS\n" : cout << "FAIL\n";
    2 == findLCA(root, 2, 4)->key ? cout << "PASS\n" : cout << "FAIL\n";

    return 0;
}
