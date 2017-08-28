#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void createThreadedBinaryTree(TreeNode *pBase)
{
  StackNode *pStackTop = NULL;
  TreeNode *pTemp;

  while (1)
  {
    while(NULL != pBase)
    {
      push(&pStackTop, pBase);
      pBase = pBase->pLeft;
    }

//    stackTraverse(&pStackTop);
    pTemp = pop(&pStackTop);
//    printf("pop1 node=%d\n", pTemp->data);
    if(NULL == pTemp->pRight)
    {
      if(0 != isStackEmpty(&pStackTop))
      {
        printf("Stack is empty\n");
        break;
      }
      pBase = pop(&pStackTop);
      pTemp->pRight = pBase;
      pTemp->isRightThreaded = 1;
      printf("%d->right=%d \n", pTemp->data, pBase->data);
    }
    pBase = pBase->pRight;
  }
}

void inOrderThreadedBinaryTree(TreeNode *pBase)
{
  while (NULL != pBase)
  {
    /* traverse leftmost node */
    while(NULL != pBase->pLeft)
    {
      pBase = pBase->pLeft;
    }
    printf("%d ", pBase->data);
    /* set the right node */
    if(pBase->isRightThreaded)
    {
      pBase = pBase->pRight;
      printf("%d ", pBase->data);
    }
    pBase = pBase->pRight;
  }
  printf("\n");
}

// Utility function to find leftmost node in atree rooted with n
TreeNode* leftMost(TreeNode *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->pLeft != NULL)
        n = n->pLeft;
 
    return n;
}
 
// C code to do inorder traversal in a threadded binary tree
void inOrder(TreeNode *root)
{
    TreeNode *cur = leftMost(root);
    while (cur != NULL)
    {
        printf("%d ", cur->data);
 
        // If this node is a thread node, then go to
        // inorder successor
        if (cur->isRightThreaded)
            cur = cur->pRight;
        else // Else go to the leftmost child in right subtree
            cur = leftMost(cur->pRight);
    }
}

int main()
{
  TreeNode *pRoot;

  pRoot = createNode(6);
  pRoot->pLeft = createNode(3);
  pRoot->pLeft->pLeft = createNode(1);
  pRoot->pLeft->pRight = createNode(5);

  pRoot->pRight = createNode(8);
  pRoot->pRight->pLeft = createNode(7);
  pRoot->pRight->pRight = createNode(11);
  pRoot->pRight->pRight->pLeft = createNode(9);
  pRoot->pRight->pRight->pRight = createNode(13);

  displayTree(pRoot, 0);
  printf("\n");

  createThreadedBinaryTree(pRoot);

  inOrderThreadedBinaryTree(pRoot);
  inOrder(pRoot);
  
  return 0;
}
