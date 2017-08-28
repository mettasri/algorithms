#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

/*****************************************************************/
/*                         LL utilities                        */
/*****************************************************************/
ListNode *createListNode(int data)
{
  ListNode *pTemp = (ListNode*)malloc(sizeof(ListNode));
  pTemp->data = data;
  pTemp->pNext = NULL;

//  printf("newNode data=%d, @ %X\n", pTemp->data, pTemp);
  return (pTemp);
}
void displayList(ListNode *pHead)
{
  printf("List: ");
  while(NULL != pHead)
  {
    printf("%X.[%d]->%X  ", pHead, pHead->data, pHead->pNext);
    pHead = pHead->pNext;
  }
  printf("\n\n");
}

void insertInList(ListNode** pHead, ListNode* pNode)
{
  ListNode *pPrev = NULL;
  ListNode *pCur  = *pHead;

  while((NULL != pCur) && (pNode->data >= pCur->data))
  {
    pPrev = pCur;
    pCur = pCur->pNext;
  }

  if(NULL == pPrev)
  {
    *pHead = pNode;
  }
  else
  {
    pPrev->pNext = pNode;
  }
  pNode->pNext = pCur;

  return;
}

void insertLastInList(ListNode** pHead, ListNode* pNode)
{
  if(NULL == *pHead)
  {
    *pHead = pNode;
    return;
  }

  ListNode *pCur  = *pHead;

  while(NULL != pCur->pNext)
  {
    pCur = pCur->pNext;
  }
  pCur->pNext = pNode;
}

void deleteFromList(ListNode** pHead, int data)
{
  ListNode *pPrev = NULL;
  ListNode *pCur  = *pHead;
  
  while((NULL != pCur) && (data != pCur->data))
  {
    pPrev = pCur;
    pCur = pCur->pNext;
  }
  if(NULL == pCur)
  {
    printf("No element found \n");
    return;
  }

  if(NULL == pPrev)
  {
    *pHead = pCur->pNext;
  }
  else
  {
    pPrev->pNext = pCur->pNext;
  }
  free(pCur);
}

/*****************************************************************/
/*                         Tree utilities                        */
/*****************************************************************/
TreeNode *createNode(int data)
{
  TreeNode *pTemp = (TreeNode *)malloc(sizeof(TreeNode));
  pTemp->data = data;
  pTemp->pLeft = NULL;
  pTemp->pRight = NULL;
//  pTemp->pNext = NULL;
  pTemp->isRightThreaded = 0;

//  printf("newNode data=%d, @ %X\n", pTemp->data, pTemp);
  return (pTemp);
}

void displayTreeCharData(TreeNode *pBase, int spaces)
{
  int i = 0;

  if(pBase == NULL)
  {
    return;
  }
  displayTreeCharData(pBase->pRight, spaces + 1);
  for(i = 0; i < spaces; i++)
    printf("   ");
  printf("%c\n", pBase->data);
  displayTreeCharData(pBase->pLeft, spaces + 1);
}

void displayTree(TreeNode *pBase, int spaces)
{
  int i = 0;

  if(pBase == NULL)
  {
    return;
  }
  displayTree(pBase->pRight, spaces + 1);
  for(i = 0; i < spaces; i++)
    printf("   ");
  printf("%d\n", pBase->data);
  displayTree(pBase->pLeft, spaces + 1);
}

void displayLeftRightCirList(TreeNode *pBase)
{
  TreeNode *pTemp = pBase;

  printf("Circular List: ");
  if(NULL == pBase)
  {
    return;
  }

  do
  {
    printf("%d  ", pBase->data);
//    printf("%X :%X<-%d->%X  ", pBase, pBase->pLeft, pBase->data, pBase->pRight);
    pBase = pBase->pRight;
  } while(pTemp != pBase);
  printf("\n");
}

void displayLeftRightList(TreeNode *pBase)
{
  printf("List: ");
  while(NULL != pBase)
  {
    printf("%d  ", pBase->data);
//    printf("%X :%X<-%d->%X  ", pBase, pBase->pLeft, pBase->data, pBase->pRight);
    pBase = pBase->pRight;
  }
  printf("\n\n");
}

int max(int x, int y)
{
  return ((x >= y) ? x : y);
}

void insertNodeIntoTree(TreeNode** pBase, TreeNode* pNode)
{
  if(NULL == *pBase)
  {
    *pBase = pNode;
  }
  else if(pNode->data < (*pBase)->data)
  {
    insertNodeIntoTree(&(*pBase)->pLeft, pNode);
  }
  else
  {
    insertNodeIntoTree(&(*pBase)->pRight, pNode);
  }
}

int hasBothChild(TreeNode* pBase)
{
  return (pBase && pBase->pLeft && pBase->pRight);
}

/*
TreeNode* insertNodeIntoTree(TreeNode* pBase, TreeNode* pNode)
{
  if(NULL == pBase)
  {
    return (pNode);
  }
  
  if(pNode->data < pBase->data)
  {
    pBase->pLeft = insertNodeIntoTree(pBase->pLeft, pNode);
    printf("pBase=%X pLeft = %X\n", pBase, pBase->pLeft);
  }
  else
  {
    pBase->pRight = insertNodeIntoTree(pBase->pRight, pNode);
  }
  return (pBase);
}
*/

/*****************************************************************/
/*                         Stack utilities                       */
/*****************************************************************/
int isStackEmpty(StackNode **pSTop)
{
  int status = 0;
  
  if(NULL == *pSTop)
  {
    status = 1;
  }
//  printf("isStackEmpty: status=%d\n", status);
  return status;
}

void push(StackNode **pSTop, TreeNode *pTNode)
{
  StackNode *pSNode = (StackNode *)malloc(sizeof(StackNode));
  
  pSNode->pTNode = pTNode;
  pSNode->pNext  = (*pSTop);
  *pSTop = pSNode;
//  printf("push data=%d \n", pTNode->data);
}

TreeNode *pop(StackNode **pSTop)
{
  TreeNode *pTNode = NULL;
  
  if(!isStackEmpty(pSTop))
  {
    pTNode = (*pSTop)->pTNode;
    *pSTop = (*pSTop)->pNext;
  }
//  printf("pop  data=%d\n", pTNode->data);
  return (pTNode);
}

TreeNode *topOfStack(StackNode **pSTop)
{
  TreeNode *pTNode = NULL;
  
  if(!isStackEmpty(pSTop))
  {
    pTNode = (*pSTop)->pTNode;
  }
//  printf("top of stack=%X \n", pTNode);
  return (pTNode);
}

void stackTraverse(StackNode **pSTop)
{
  StackNode *pSNode = NULL;
  
  if(!isStackEmpty(pSTop))
  {
    pSNode = *pSTop;
    
    printf("Stack Elements: ");
    while(pSNode)
    {
      printf("%d ", pSNode->pTNode->data);
      pSNode = pSNode->pNext;
    }
  }
  printf("\n");
}

/*****************************************************************/
/*                         Queue utilities                       */
/*****************************************************************/
QueueNode* createQueue(int size)
{
  int i;
  QueueNode *pQNode = (QueueNode *)malloc(sizeof(QueueNode));
  
  pQNode->front  = -1;
  pQNode->rear   = -1;
  pQNode->size   = size;
  pQNode->pQTree = (TreeNode **)malloc(size * sizeof(TreeNode *));
  
  for(i = 0; i < size; i++)
  {
    pQNode->pQTree[i] = NULL;
  }

  return (pQNode);
}

int isQueueEmpty(QueueNode *pQBase)
{
  return (pQBase->front == -1);
}

int isQueueFull(QueueNode *pQBase)
{
  return (pQBase->rear == (pQBase->size - 1));
}

int hasOnlyOneItemInQueue(QueueNode *pQBase)
{
  return (pQBase->rear == pQBase->front);
}

int noOfEleInQueue(QueueNode *pQBase)
{
  if(isQueueEmpty(pQBase))
    return 0;
  if(hasOnlyOneItemInQueue(pQBase))
    return 1;

  return (pQBase->rear - pQBase->front + 1);
}

void enQueue(QueueNode *pQBase, TreeNode *pTNode)
{
  if(isQueueFull(pQBase)) return;
  
  pQBase->pQTree[++pQBase->rear] = pTNode;
//  printf("enQueue: %d\n", pTNode->data);
  
  if(isQueueEmpty(pQBase)) pQBase->front++;
}

TreeNode* deQueue(QueueNode *pQBase)
{
  if(isQueueEmpty(pQBase)) return NULL;
  
  TreeNode *pTNode = pQBase->pQTree[pQBase->front];
  
  if(hasOnlyOneItemInQueue(pQBase))
  {
    pQBase->rear  = -1;
    pQBase->front = -1;
  }
  else
  {
    pQBase->front++;
  }
  
//  printf("deQueue: %d\n", pTNode->data);
  return (pTNode);
}

TreeNode* getFront(QueueNode *pQBase)
{
  return (pQBase->pQTree[pQBase->front]);
}

void displayQueue(QueueNode *pQBase)
{
  int i;

  if(isQueueEmpty(pQBase)) return;
  
//  printf("Queue front=%d, rear=%d : ", pQBase->front, pQBase->rear);
  printf("Queue: ");
  for(i = pQBase->front; i <= pQBase->rear; i++)
  {
    printf("%d ", (pQBase->pQTree[i])->data);
  }
  printf("\n");
}
