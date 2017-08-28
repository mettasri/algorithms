#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
struct node *root = NULL;
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    printf("node [%d], leftHeight [%d] rightHeight[%d]\n", N->key, height(N->left), height(N->right));
    return height(N->left) - height(N->right);
}

void printTree(struct node* node, int h)
{
  if(NULL != node)
  {
    int i;

    printTree(node->right, h+1);
    for(i = 0; i < h; i++)
    {
      printf("  ");
    }
    printf("%d\n", node->key);
    printTree(node->left, h+1);
  }
}
 
struct node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
    printTree(root, 0); printf("\n");
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
      printf("Left Left: key [%d] < node->left->key [%d] => [Right Rotate @ %d ]\n\n", \
          key, node->right->key, node->key);
      return rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
      printf("Right Right: key [%d] > node->right->key [%d] => [Left Rotate @ %d ]\n\n", \
          key, node->right->key, node->key);
      return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
      printf("Left Right: key [%d] > node->left->key [%d] => [Left Rotate @ %d, Right Rotate @%d ]\n\n", \
          key, node->left->key, node->left->key, node->key);
        node->left =  leftRotate(node->left);
        printTree(root, 0); printf("\n");
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
      printf("Right Left: key [%d] < node->right->key [%d] => [Right Rotate @ %d, Left Rotate @ %d ]\n\n", \
          key, node->right->key, node->right->key, node->key);
        node->right = rightRotate(node->right);
        printTree(root, 0); printf("\n");
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  /* Constructing tree given in the above figure */
//  root = insert(root, 7); printTree(root, 0); printf("\n\n");
//  root = insert(root, 5); printTree(root, 0); printf("\n\n");
//  root = insert(root, 30); printTree(root, 0); printf("\n\n");
//  root = insert(root, 20); printTree(root, 0); printf("\n\n");
//  root = insert(root, 15); printTree(root, 0); printf("\n\n");
//  root = insert(root, 6); printTree(root, 0); printf("\n\n");
//  root = insert(root, 10); printTree(root, 0); printf("\n\n");
 
/*  
// Right Left case: 
  root = insert(root, 10); printTree(root, 0); printf("\n\n");
  root = insert(root, 30); printTree(root, 0); printf("\n\n");
  root = insert(root, 20); printTree(root, 0); printf("\n\n");
*/
/*         
 *         10                             10                               20
 *           \                              \                             /  \
 *           30    ==[Right Rotate @30]==>  20  ==[Left Rotate @10]==>  10    30
 *          /                                 \
 *         20                                 30
 */

  
// Left Right case: 
  root = insert(root, 30); printTree(root, 0); printf("\n\n");
  root = insert(root, 10); printTree(root, 0); printf("\n\n");
  root = insert(root, 20); printTree(root, 0); printf("\n\n");

/*         
 *         30                                30                            20
 *        /                                 /                             /  \
 *       10    ==[Left Rotate @10]==>     20  == [Right Rotate @30]==>  10    30
 *         \                             /
 *          20                         10
 */

/*  
  root = insert(root, 10); printTree(root, 0); printf("\n\n");
  root = insert(root, 20); printTree(root, 0); printf("\n\n");
  root = insert(root, 30); printTree(root, 0); printf("\n\n");
  root = insert(root, 40); printTree(root, 0); printf("\n\n");
  root = insert(root, 50); printTree(root, 0); printf("\n\n");
  root = insert(root, 25); printTree(root, 0); printf("\n\n");
*/
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
 
  return 0;
}

