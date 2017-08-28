#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode* removeAllNodesInPath(TreeNode *pBase, TreeNode **pHead)
{
  if(NULL == pBase) return NULL;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    pBase->pRight = *pHead;
    if(NULL != *pHead)
      (*pHead)->pLeft = pBase;
    *pHead = pBase;

    return NULL;
  }

  pBase->pRight = removeAllNodesInPath(pBase->pRight, pHead);
  pBase->pLeft  = removeAllNodesInPath(pBase->pLeft, pHead);

  return (pBase);
}

TreeNode *pRoot = NULL;

int main()
{
  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);

  pRoot->pLeft->pLeft->pLeft = createNode(7);
  pRoot->pLeft->pLeft->pRight = createNode(8);
  
  pRoot->pRight = createNode(3);
  pRoot->pRight->pRight = createNode(6);
  pRoot->pRight->pRight->pLeft = createNode(9);
  pRoot->pRight->pRight->pRight = createNode(10);
  
  
  displayTree(pRoot, 0);
  printf("\n");

  TreeNode *pHead = NULL;
  
  pRoot = removeAllNodesInPath(pRoot, &pHead);
  
  displayLeftRightList(pHead);

  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}

