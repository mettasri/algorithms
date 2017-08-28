#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"
using namespace std;

#define true 1
#define false 0

TreeNode *getNextRight(TreeNode* pBase)
{
  while(pBase)
  {
    if(NULL != pBase->pLeft) return pBase->pLeft;
    if(NULL != pBase->pRight) return pBase->pRight;
    pBase = pBase->pNext;
  }
  return NULL;
}

/* works only for the Complete Binary Tree */
void connecteNodesAtSameLevel(TreeNode *pBase)
{
  if(NULL == pBase)  return;

  if(pBase->pLeft)
  {
    pBase->pLeft->pNext = pBase->pRight ? pBase->pRight : getNextRight(pBase->pNext);
    printf("%d l %d next %d  \n", pBase->data, pBase->pLeft->data, pBase->pLeft->pNext ? pBase->pLeft->pNext->data : 0);
    connecteNodesAtSameLevel(pBase->pNext);
  }
  if(pBase->pRight)
  {
    pBase->pRight->pNext = getNextRight(pBase->pNext);
    printf("%d r %d next %d \n", pBase->data, pBase->pRight->data, pBase->pRight->pNext? pBase->pRight->pNext->data : 0);
  }

  connecteNodesAtSameLevel(pBase->pLeft);
  connecteNodesAtSameLevel(pBase->pRight);
}

void connectRecur(TreeNode* p)
{
  // Base case
  if (!p)
    return;

  /* Before setting nextRight of left and right children, set nextRight
     of other nodes at same level */
  if (p->pNext != NULL)
    connectRecur(p->pNext);

  /* Set the nextRight pointer for p's left child */
  if (p->pLeft)
  {
    if (p->pRight)
    {
      p->pLeft->pNext = p->pRight;
      printf("%d l %d next %d  \n", p->data, p->pLeft->data, p->pLeft->pNext ? p->pLeft->pNext->data : 0);
      p->pRight->pNext = getNextRight(p->pNext);
      printf("%d r %d next %d \n", p->data, p->pRight->data, p->pRight->pNext? p->pRight->pNext->data : 0);
    }
    else
    {
      p->pLeft->pNext = getNextRight(p->pNext);
      printf("%d l %d next %d  \n", p->data, p->pLeft->data, p->pLeft->pNext ? p->pLeft->pNext->data : 0);
    }
    /* Recursively call for next level nodes.  Note that we call only
       for left child. The call for left child will call for right child */
    connectRecur(p->pLeft);
  }

  /* If left child is NULL then first node on next level will be either
     right child or getNextRight(p->pNext) */
  else if (p->pRight)
  {
    p->pRight->pNext = getNextRight(p->pNext);
    printf("%d r %d next %d \n", p->data, p->pRight->data, p->pRight->pNext ? p->pRight->pNext->data : 0);
    connectRecur(p->pRight);
  }
  else
    connectRecur(getNextRight(p->pNext));
}

void connectByQueue(TreeNode *pBase)
{
  int count;
  queue<TreeNode*> myQ;
  TreeNode *pPrev = NULL;
  TreeNode *pCur = NULL;

  myQ.push(pBase);

  while(!myQ.empty())
  {
    count = myQ.size();
    pPrev = NULL;
    while(count)
    {
      pCur = myQ.front();;
      cout << "front: " << pCur->data << endl;
      pCur->pNext = pPrev;
      pPrev = pCur;
      myQ.pop();
      if(pCur && pCur->pRight)
        myQ.push(pCur->pRight);
      if(pCur && pCur->pLeft)
        myQ.push(pCur->pLeft);
      count--;
    }
  }
}

void displayNodeNext(TreeNode* pBase, int flag)
{
  TreeNode *pTemp = pBase;
  if(NULL == pBase) return;

  if(flag)
  {
    while(pTemp)
    {
      printf("%d ", pTemp->data);
      pTemp = pTemp->pNext;
    }
    printf("\n");
  }
  if(pBase->pLeft)
    displayNodeNext(pBase->pLeft, true);
  else if(pBase->pRight)
    displayNodeNext(pBase->pRight, true);
  else if(pBase->pNext)
    displayNodeNext(pBase->pNext, false);
}

TreeNode *pRoot = NULL;

int main()
{
  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  //  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);
  //  pRoot->pLeft->pLeft->pLeft = createNode(8);
  //  pRoot->pLeft->pLeft->pRight = createNode(9);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);
  pRoot->pRight->pRight->pLeft = createNode(10);
  pRoot->pRight->pRight->pRight = createNode(11);

  displayTree(pRoot, 0);
  printf("\n");

  /* works only for the Complete Binary Tree */
  pRoot->pNext = NULL;

  //  connecteNodesAtSameLevel(pRoot);
  //  connectRecur(pRoot);
  connectByQueue(pRoot);

  displayNodeNext(pRoot, true);

  return 0;
}

