#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

/*
int removeAllNodesInPath(TreeNode *pBase, int sum, int k)
{
  if(NULL == pBase)  return 1;
  
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return ((sum + pBase->data) >= k ? 0 : 1);
  }
  
  int left  = removeAllNodesInPath(pBase->pLeft,  sum + pBase->data, k);
  int right = removeAllNodesInPath(pBase->pRight, sum + pBase->data, k);
  
  if(left && NULL != pBase->pLeft)
  {
    printf("left freed: %d\n", pBase->data);  
    free(pBase->pLeft);
    pBase->pLeft = NULL;
  }
  if(right && NULL != pBase->pRight)
  {
    printf("right freed: %d\n", pBase->data);  
    free(pBase->pRight);
    pBase->pRight = NULL;
  }
  if(left && right)
  {
    return 1;
  }
  return 0;
}
*/

TreeNode* removeAllNodesInPath(TreeNode *pBase, int k, int *pSum)
{
  if(NULL == pBase)  return NULL;
  
  int lSum, rSum;
  lSum = rSum = *pSum + pBase->data;
  printf("%d \n", pBase->data);
  if(lSum >= k)  return pBase;
  
  pBase->pLeft  = removeAllNodesInPath(pBase->pLeft, k, &lSum);
  pBase->pRight = removeAllNodesInPath(pBase->pRight, k, &rSum);

  printf("=> %d \n", pBase->data);
  
  if(!pBase->pLeft && !pBase->pRight)
  {
    free(pBase);
    return (NULL);
  }
  return (pBase);
}
TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pNode;

  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pLeft->pLeft = createNode(8);
  //pRoot->pLeft->pLeft->pLeft->pLeft = createNode(1);

  pRoot->pLeft->pLeft->pRight = createNode(9);
  pRoot->pLeft->pLeft->pRight->pLeft = createNode(13);
  pRoot->pLeft->pLeft->pRight->pRight = createNode(14);
  pRoot->pLeft->pLeft->pRight->pRight->pLeft = createNode(15);

  pRoot->pLeft->pRight = createNode(5);
  pRoot->pLeft->pRight->pLeft = createNode(12);
  
  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);
  pRoot->pRight->pRight->pLeft = createNode(10);
  pRoot->pRight->pRight->pLeft->pRight = createNode(11);
  
  
  displayTree(pRoot, 0);
  printf("\n\n\n\n");
  
  //(1 == removeAllNodesInPath(pRoot, 0, 20)) ? pRoot=NULL : 0;

  int sum = 0;
  pRoot = removeAllNodesInPath(pRoot, 20, &sum);
  
  printf("\n\n\n");
  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}

