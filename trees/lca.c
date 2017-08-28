#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode* lca(TreeNode *pBase, int k1, int k2)
{
  if(NULL == pBase)  return NULL;

  if((k1 == pBase->data) || (k2 == pBase->data))
  {
    printf("data=%d \n", pBase->data);
    return pBase;
  }

  TreeNode *pLeft1 = lca(pBase->pLeft,  k1, k2);
  TreeNode *pRight1 = lca(pBase->pRight, k1, k2);

  if((pLeft1) && (pRight1))
  {
    return pBase;
  }
  
  return (NULL != pLeft1 ? pLeft1: pRight1);
}

TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pNode;

  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);
  
  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pLeft->pRight = createNode(8);
  pRoot->pRight->pRight = createNode(7);
  
  displayTree(pRoot, 0);
  printf("\n\n\n\n");
  
  pNode = lca(pRoot, 2, 4);
  printf("lca(2, 4): %d\n", pNode ? pNode->data : 0);
  return 0;
}

