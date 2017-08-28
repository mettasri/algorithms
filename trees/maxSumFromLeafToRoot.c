#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void maxSumFromLeafToRoot(TreeNode *pBase, int *max, int sum, TreeNode **pLeaf)
{
  if(NULL == pBase)  return;

  sum += pBase->data;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    if(sum > *max)
    {
      *pLeaf = pBase;
      *max = sum;
    }
    return;
  }

  maxSumFromLeafToRoot(pBase->pLeft, max, sum, pLeaf);
  maxSumFromLeafToRoot(pBase->pRight, max, sum, pLeaf);
}

int printLeafToRootPath(TreeNode *pBase, TreeNode *pLeaf)
{
  if(NULL == pBase) return 0;
  
  if((pBase == pLeaf) || printLeafToRootPath(pBase->pLeft, pLeaf)
      || printLeafToRootPath(pBase->pRight, pLeaf))
  {
    printf("%d ", pBase->data);
    return 1;
  }
  return 0;
}

void maxSum(TreeNode *pBase)
{
  int max = 0, sum;
  TreeNode *pLeaf = NULL;

  maxSumFromLeafToRoot(pBase, &max, sum, &pLeaf);
  printf("Leaf=%X->%d, max=%d\n", pLeaf, pLeaf->data, max);
  printLeafToRootPath(pBase, pLeaf);
}

TreeNode *pRoot = NULL;

int main()
{
  int i;
  TreeNode *pNode;

  pRoot = createNode(10);
  pRoot->pLeft = createNode(-2);
  pRoot->pLeft->pLeft = createNode(8);
  pRoot->pLeft->pRight = createNode(-4);
  pRoot->pLeft->pRight->pLeft = createNode(30);

  pRoot->pRight = createNode(7);
  pRoot->pRight->pRight = createNode(9);

  displayTree(pRoot, 0);
  printf("\n");

  maxSum(pRoot);

  return 0;
}
