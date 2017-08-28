#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void insertToCompBt(TreeNode **pTBase, QueueNode *pQBase, int data)
{
  TreeNode *pTNode;
  TreeNode *pTTemp = createNode(data);

  if(NULL == *pTBase)
  {
    *pTBase = pTTemp;
  }
  
  else
  {
    pTNode = getFront(pQBase);
    if(NULL == pTNode->pLeft)
    {
      pTNode->pLeft = pTTemp;
    }
    else if(NULL == pTNode->pRight)
    {
      pTNode->pRight = pTTemp;
    }

    if(hasBothChild(pTNode))
    {
      deQueue(pQBase);
//      displayQueue(pQBase);
    }
  }
  enQueue(pQBase, pTTemp);
//  displayQueue(pQBase);
}

int main()
{
  int i;
  TreeNode  *pTreeRoot = NULL;
  QueueNode *pQueue = createQueue(20);


  for(i = 1; i <= 16; i++)
  {
    insertToCompBt(&pTreeRoot, pQueue, i);
  }

  displayTree(pTreeRoot, 0);
  printf("\n");
  
  return 0;
}
