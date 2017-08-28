#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"


int convertToSumTree(TreeNode *pBase)
{
  int old_val;
  
  if(NULL == pBase)  return 0;
  old_val = pBase->data;
  pBase->data = convertToSumTree(pBase->pLeft) + convertToSumTree(pBase->pRight);
  return (old_val + pBase->data);
}

TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pNode;

  pRoot = createNode(10);
  pRoot->pLeft = createNode(-2);
  pRoot->pLeft->pLeft = createNode(8);
  pRoot->pLeft->pRight = createNode(-4);

  pRoot->pRight = createNode(6);
  pRoot->pRight->pLeft = createNode(7);
  pRoot->pRight->pRight = createNode(5);

  displayTree(pRoot, 0);
  printf("\n");

  convertToSumTree(pRoot);

  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}
