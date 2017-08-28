#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"
/*
TreeNode* nextRightOfNode(TreeNode *pBase, int k, int level, int *keyLevel)
{
  TreeNode *pTemp;

  if(NULL == pBase)  return NULL;
//  printf("data=%d, level=%d\n", pBase->data, level);
  
  if(k == pBase->data)
  {
    *keyLevel = level;
    return NULL;
  }
  else if(*keyLevel == level)
  {
    return pBase;
  }

  if((pTemp = nextRightOfNode(pBase->pLeft, k, level + 1, keyLevel))
  || (pTemp = nextRightOfNode(pBase->pRight, k, level + 1, keyLevel)))
  {
//    printf("return data=%d \n", pTemp ? pTemp->data : 0);
    return pTemp;
  }
//  printf("return NULL for %d \n", pBase ? pBase->data : 0);
  return NULL;
}
*/
TreeNode* nextRightOfNode(TreeNode *pBase, int key)
{
  int noOfEle;
  QueueNode *pQueue = createQueue(10);
  enQueue(pQueue, pBase);

  while(!isQueueEmpty(pQueue))
  {
    noOfEle = noOfEleInQueue(pQueue);
//    printf("noOfEle=%d\n", noOfEle);
    while(noOfEle)
    {
      pBase = deQueue(pQueue);
      noOfEle--;
      if(key == pBase->data)
      {
//        printf("Ele found\n");
        if(noOfEle > 0)
          return deQueue(pQueue);
        else
          return NULL;
      }

      if(pBase->pLeft)
      {
//        printf("enqueued %d\n", pBase->pLeft->data);
        enQueue(pQueue, pBase->pLeft);
      }
      if(pBase->pRight)
      {
//        printf("enqueued %d\n", pBase->pRight->data);
        enQueue(pQueue, pBase->pRight);
      }
    }
  }
  return NULL;
}

TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pNode;

  pRoot = createNode(10);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(8);
  pRoot->pLeft->pRight = createNode(4);
  
  pRoot->pRight = createNode(6);
  pRoot->pRight->pRight = createNode(5);
  
  displayTree(pRoot, 0);
  printf("\n\n\n\n");
  
  int keyLevel = 0;
//  pNode = nextRightOfNode(pRoot, 4, 1, &keyLevel);
  pNode = nextRightOfNode(pRoot, 4);
  
  if(NULL != pNode)
    printf("Next right=%d\n", pNode->data);
  else
    printf("No next right found\n");

  return 0;
}

