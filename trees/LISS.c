// A naive recursive implementation of Largest Independent Set problem
#include <stdio.h>
#include <stdlib.h>
 
// A utility function to find max of two integers
int max(int x, int y) { return (x > y)? x: y; }
 
/* A binary tree node has data, pointer to left child and a pointer to 
   right child */
struct node
{
    int data;
    struct node *left, *right;
};
 
// The function returns size of the largest independent set in a given 
// binary tree
int LISS(struct node *root)
{
    if (root == NULL)
       return 0;
 
    // Caculate size excluding the current node
    int size_excl = LISS(root->left) + LISS(root->right);
 
    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
       size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
       size_incl += LISS(root->right->left) + LISS(root->right->right);
 
    // Return the maximum of two sizes
    printf("data=%d, size_incl=%d, size_excl=%d\n", root->data, size_incl, size_excl);
    return max(size_incl, size_excl);
}
 
 
// A utility function to create a node
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void displayTree(struct node *pBase, int spaces)
{
  int i = 0;

  if(pBase == NULL)
  {
    return;
  }
  displayTree(pBase->right, spaces + 1);
  for(i = 0; i < spaces; i++)
    printf("   ");
  printf("%d\n", pBase->data);
  displayTree(pBase->left, spaces + 1);
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
//    root->left->left          = newNode(4);
//    root->left->right         = newNode(12);
//    root->left->right->left   = newNode(10);
//    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
//    root->right->right        = newNode(25);
    
    displayTree(root, 0);

    printf ("Size of the Largest Independent Set is %d ", LISS(root));
 
    return 0;
}
