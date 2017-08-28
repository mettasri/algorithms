#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int sumNumFormedFromRootToLeafPath(TreeNode* pBase, int data)
{
  if(NULL == pBase)  return 0;
  
  data = data*10 + pBase->data;

  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return data;
  }
  int left  = sumNumFormedFromRootToLeafPath(pBase->pLeft, data);
  int right = sumNumFormedFromRootToLeafPath(pBase->pRight, data);
  printf("data=%d l=%d r=%d \n", pBase->data, left, right);

  return (left + right);
}

TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pNode;

  pRoot = createNode(6);
  pRoot->pLeft = createNode(3);
  pRoot->pLeft->pLeft = createNode(2);
  pRoot->pLeft->pRight = createNode(5);
  pRoot->pLeft->pRight->pLeft = createNode(7);
  pRoot->pLeft->pRight->pRight = createNode(4);
  
  pRoot->pRight = createNode(5);
  pRoot->pRight->pRight = createNode(4);
  
  displayTree(pRoot, 0);
  printf("\n\n\n\n");
  
  printf("sum=%d\n", sumNumFormedFromRootToLeafPath(pRoot, 0));

  return 0;
}

