#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode *pRoot = NULL;


int isAllLeavesAtSameLevel(TreeNode* pBase, int level)
{
  if(NULL == pBase) return 0;

  if(NULL == pBase->pLeft && NULL == pBase->pRight) return level;

  int l = isAllLeavesAtSameLevel(pBase->pLeft, level + 1);
  int r = isAllLeavesAtSameLevel(pBase->pRight, level + 1);

  printf("data=%d level=%d l=%d r=%d\n", pBase->data, level, l, r);

  if(pBase->pLeft && pBase->pRight)
    return (l == r ? l : 0);
  else
    return ((l == 0) ? (r) : l);
}

int main()
{
  TreeNode *pNode;

  pRoot = createNode(12);
  pRoot->pLeft = createNode(5);
  pRoot->pLeft->pLeft = createNode(3);
  pRoot->pLeft->pRight = createNode(9);
  pRoot->pLeft->pLeft->pLeft = createNode(1);
  pRoot->pLeft->pRight->pRight = createNode(2);


  displayTree(pRoot, 0);
  printf("\n");

  isAllLeavesAtSameLevel(pRoot, 1) ? printf("YES\n") : printf("NO\n");

  return 0;
}

