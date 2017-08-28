#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void preorderMorrisTraversal(TreeNode *pBase)
{
  TreeNode *pCur = pBase, *pTemp;

  while(pCur)
  {
    if(NULL == pCur->pLeft)
    {
      printf("%d ", pCur->data);
      pCur = pCur->pRight;
    }
    else
    {
      pTemp = pCur->pLeft;
      while(pTemp->pRight != NULL && pTemp->pRight != pCur)
      {
        pTemp = pTemp->pRight;
      }
      /* make the threaded link */
      if(NULL == pTemp->pRight)
      {
        pTemp->pRight = pCur;
        printf("%d ", pCur->data);
        pCur = pCur->pLeft;
      }
      else /* break the threaded link */
      {
        pTemp->pRight = NULL;
        pCur = pCur->pRight;
      }
    }
  }
  printf("\n");
}

void inorderMorrisTraversal(TreeNode *pBase)
{
  TreeNode *pCur = pBase, *pTemp;

  while(pCur)
  {
    if(NULL == pCur->pLeft)
    {
      printf("%d ", pCur->data);
      pCur = pCur->pRight;
    }
    else
    {
      pTemp = pCur->pLeft;
      while(pTemp->pRight != NULL && pTemp->pRight != pCur)
      {
        pTemp = pTemp->pRight;
      }
      /* make the threaded link */
      if(NULL == pTemp->pRight)
      {
        pTemp->pRight = pCur;
        pCur = pCur->pLeft;
      }
      else /* break the threaded link */
      {
        pTemp->pRight = NULL;
        printf("%d ", pCur->data);
        pCur = pCur->pRight;
      }
    }
  }
  printf("\n");
}

/* one stack */
void inOrderTreeTraversal(TreeNode *pBase)
{
  int flag = 1;
  StackNode *pStackTop = NULL;
  TreeNode  *pCur = pBase;
/*
  while(flag)
  {
    if(NULL != pCur)
    {
//      printf("%d ", pCur->data);  // preOrder traversal
      push(&pStackTop, pCur);
      pCur = pCur->pLeft;
    }
    else
    {
      if(!isStackEmpty(&pStackTop))
      {
        pCur = pop(&pStackTop);
        printf("%d ", pCur->data); // inOrder traversal
        pCur = pCur->pRight;
      }
      else
      {
        flag = 0;
      }
    }
  }
*/
  do
  {
    if(NULL != pCur)
    {
//      printf("%d ", pCur->data);  // preOrder traversal
      push(&pStackTop, pCur);
      pCur = pCur->pLeft;
    }
    else
    {
      pCur = pop(&pStackTop);
      printf("%d ", pCur->data); // inOrder traversal
      pCur = pCur->pRight;
    }
  }while(!isStackEmpty(&pStackTop) || pCur);

  printf("\n");
}

/* one stack */
void preOrderTreeTraversal(TreeNode *pBase)
{
  StackNode *pStackTop = NULL;
  TreeNode  *pNode;

  push(&pStackTop, pBase);
  
  while(!isStackEmpty(&pStackTop))
  {
    pNode = pop(&pStackTop);
    printf("%d ", pNode->data);
    
    if(pNode->pRight)
      push(&pStackTop, pNode->pRight);
    if(pNode->pLeft)
      push(&pStackTop, pNode->pLeft);
  }
  printf("\n");
}

/* post order using 2 stacks */
void postOrderTreeTraversal_twoStacks(TreeNode *pBase)
{
  StackNode *pStackTop1 = NULL;
  StackNode *pStackTop2 = NULL;
  TreeNode  *pNode;

  push(&pStackTop1, pBase);
  
  while(!isStackEmpty(&pStackTop1))
  {
    pNode = pop(&pStackTop1);
    push(&pStackTop2, pNode);
    if(pNode->pLeft)
      push(&pStackTop1, pNode->pLeft);
    if(pNode->pRight)
      push(&pStackTop1, pNode->pRight);
  }
  while(!isStackEmpty(&pStackTop2))
  {
    pNode = pop(&pStackTop2);
    printf("%d ", pNode->data);
  }
  printf("\n");
}

/* post order using 1 stack */
void postOrderTreeTraversal_oneStack(TreeNode *pBase)
{
  StackNode *pStackTop = NULL;
  TreeNode  *pCur = pBase;
  TreeNode  *pNode;

  do
  {
    while(pCur)
    {
      if(pCur->pRight)
      {
        push(&pStackTop, pCur->pRight);
      }
      push(&pStackTop, pCur);
      pCur = pCur->pLeft;
    }
    
    pNode = pop(&pStackTop);
    if((pNode->pRight) && (pNode->pRight == topOfStack(&pStackTop)))
    {
      pCur = pop(&pStackTop);
      push(&pStackTop, pNode);
    }
    else
    {
      printf("%d ", pNode->data);
      pNode = NULL;
    }
  } while(!isStackEmpty(&pStackTop));
  
  printf("\n");
}

/* two stacks */
void printSpiral(TreeNode *pBase)
{
  StackNode *pStack1 = NULL;
  StackNode *pStack2 = NULL;
  TreeNode  *pNode;

  push(&pStack1, pBase);
  while(! isStackEmpty(&pStack1) || ! isStackEmpty(&pStack2))
  {
    while(! isStackEmpty(&pStack1))
    {
      pNode = pop(&pStack1);
      printf("%d ", pNode->data);
      if(pNode->pRight)
      {
        push(&pStack2, pNode->pRight);
      }
      if(pNode->pLeft)
      {
        push(&pStack2, pNode->pLeft);
      }
    }
    while(! isStackEmpty(&pStack2))
    {
      pNode = pop(&pStack2);
      printf("%d ", pNode->data);
      if(pNode->pLeft)
      {
        push(&pStack1, pNode->pLeft);
      }
      if(pNode->pRight)
      {
        push(&pStack1, pNode->pRight);
      }
    }
  }
  printf("\n");
}

/* one queue and one stack */
void reverseLevelOrder(TreeNode *pBase)
{
  QueueNode *pQueue = createQueue(10);
  StackNode *pStack = NULL;
  TreeNode *pTemp;

  enQueue(pQueue, pBase);
  while(! isQueueEmpty(pQueue))
  {
    pTemp = deQueue(pQueue);
    push(&pStack, pTemp);
    if(pTemp->pRight)
    {
      enQueue(pQueue, pTemp->pRight);
    }
    if(pTemp->pLeft)
    {
      enQueue(pQueue, pTemp->pLeft);
    }
  }

  while(! isStackEmpty(&pStack))
  {
    pTemp = pop(&pStack);
    printf("%d ", pTemp->data);
  }
  printf("\n");
}

/* one queue */
void printLevelOrder(TreeNode *pBase)
{
  int n;
  QueueNode *pQueue = createQueue(10);
  TreeNode *pTemp;

  enQueue(pQueue, pBase);
  
  while(! isQueueEmpty(pQueue))
  {
    n = noOfEleInQueue(pQueue);
    
    while(n)
    {
      pTemp = deQueue(pQueue);
      printf("%d ", pTemp->data);
      if(pTemp->pLeft)
      {
        enQueue(pQueue, pTemp->pLeft);
      }
      if(pTemp->pRight)
      {
        enQueue(pQueue, pTemp->pRight);
      }
      n--;
    }
    printf("\n");
  }
}

TreeNode  *pTreeRoot;

int main()
{
  TreeNode *pNode;

  pTreeRoot = createNode(1);
  pTreeRoot->pLeft = createNode(2);
  pTreeRoot->pLeft->pLeft = createNode(4);
  pTreeRoot->pLeft->pLeft->pLeft = createNode(8);
  pTreeRoot->pLeft->pRight = createNode(5);
  pTreeRoot->pLeft->pRight->pRight = createNode(9);

  pTreeRoot->pRight = createNode(3);
  pTreeRoot->pRight->pLeft = createNode(6);
  pTreeRoot->pRight->pRight = createNode(7);
  pTreeRoot->pRight->pRight->pLeft = createNode(10);

  displayTree(pTreeRoot, 0);
  printf("\n");

  printf("Inorder   : ");
  inOrderTreeTraversal(pTreeRoot);
  printf("Inorder   : ");
  inorderMorrisTraversal(pTreeRoot);

  printf("Preorder  : ");
  preOrderTreeTraversal(pTreeRoot);
  printf("Preorder  : ");
  preorderMorrisTraversal(pTreeRoot);

  printf("Postorder : ");
  postOrderTreeTraversal_oneStack(pTreeRoot);
  printf("Postorder : ");
  postOrderTreeTraversal_twoStacks(pTreeRoot);
  
  /* Level order traversal in spiral form */
  printf("Spiral (two stacks)      : ");
  printSpiral(pTreeRoot);

  /* Print level order traversal line by line */
  printf("LevelOrder (queue)       : \n");
  printLevelOrder(pTreeRoot);

  /* Reverse Level Order Traversal */
  printf("RevLevelOr (queue, stack): ");
  reverseLevelOrder(pTreeRoot);

  return 0;
}
