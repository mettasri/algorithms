#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int diff(int l, int r)
{
  return (l > r ? l - r : r - l);
}

/*
int isHeightBalanced(TreeNode *pBase, int *height)
{
  int lh, rh;

  if(NULL == pBase)
  {
    *height = 0;
    return 1;
  }

  if(isHeightBalanced(pBase->pLeft, &lh) && isHeightBalanced(pBase->pRight, &rh) && diff(lh, rh) <= 1)
  {
    printf("data=%d, lh=%d, rh=%d \n", pBase->data, lh, rh);
    *height = ((lh > rh) ? lh : rh) + 1;
    return 1;
  }
  return 0;
}
*/

int min(int x, int y) {return (x < y ? x : y);}

int maxDepth(TreeNode *pBase)
{
  if(!pBase) return 0;

  return 1 + max(maxDepth(pBase->pLeft), maxDepth(pBase->pRight));
}

int minDepth(TreeNode *pBase)
{
  if(!pBase) return 0;

  return 1 + min(minDepth(pBase->pLeft), minDepth(pBase->pRight));
}

int isHeightBalanced(TreeNode *pBase)
{
  return ((maxDepth(pBase) - minDepth(pBase)) <= 1);
}

int main()
{
  TreeNode *pRoot = NULL;
  int h;
//  diameter of a tree
  pRoot = createNode(1);

  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);
  pRoot->pLeft->pRight->pLeft = createNode(9);
//  pRoot->pLeft->pRight->pLeft->pRight = createNode(10);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);
  
  displayTree(pRoot, 0);
  printf("\n");

//  if(1 == isHeightBalanced(pRoot, &h))
  if(1 == isHeightBalanced(pRoot))
  {
    printf("Height-balanced Tree \n\n");
  }
  else
  {
    printf("Not a height-balanced Tree \n\n");
  }

  return 0;
} 
