#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void deepestLeftLeafNode(TreeNode *pBase, int level, int *maxLeftLevel, int isLeft, TreeNode **pLeftNode)
{
  if(NULL == pBase) return;
  if(isLeft && (NULL == pBase->pLeft) && (NULL == pBase->pRight) && (level > *maxLeftLevel))
  {
    *maxLeftLevel = level;
    *pLeftNode = pBase;
    return;
  }

  deepestLeftLeafNode(pBase->pLeft, level + 1, maxLeftLevel, 1, pLeftNode);
  deepestLeftLeafNode(pBase->pRight, level + 1, maxLeftLevel, 0, pLeftNode);
}

TreeNode *pRoot = NULL;

int main()
{
  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(5);
  pRoot->pRight->pLeft->pRight = createNode(7);
  pRoot->pRight->pLeft->pRight->pLeft = createNode(9);
  pRoot->pRight->pRight = createNode(6);
  pRoot->pRight->pRight->pRight = createNode(8);
  pRoot->pRight->pRight->pRight->pRight = createNode(10);

  displayTree(pRoot, 0);
  printf("\n");
  int level = 0, maxLeftLevel = 0;
  TreeNode *pLeftNode = NULL;

  deepestLeftLeafNode(pRoot, level, &maxLeftLevel, 0, &pLeftNode);
  
  printf("deepest left leaf node: %d\n", pLeftNode->data);

  return 0;
}

