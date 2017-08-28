#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode *pTreeRoot;

/*
int depthOfDeepestOddLevel(TreeNode *pBase, int isOdd)
{
  if(NULL == pBase) return 0;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return (isOdd == 1 ? 1 : 0);
  }

  int left = depthOfDeepestOddLevel(pBase->pLeft, -isOdd);
  int right = depthOfDeepestOddLevel(pBase->pRight, -isOdd);

//  printf("%d l=%d r=%d\n", pBase->data, left, right);

  if(left || right)
    return ((left > right ? left : right) + 1);
  else
    return 0;
}
*/

int depthOfDeepestOddLevel(TreeNode *pBase, int level)
{
  if(NULL == pBase) return 0;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
    return ((level & 1) ? level : 0);

  return (max(depthOfDeepestOddLevel(pBase->pLeft, level + 1), 
              depthOfDeepestOddLevel(pBase->pRight, level + 1)));
}

int main()
{

  pTreeRoot = createNode(1);
  pTreeRoot->pLeft = createNode(2);
  pTreeRoot->pLeft->pLeft = createNode(4);

  pTreeRoot->pRight = createNode(3);
  pTreeRoot->pRight->pLeft = createNode(5);
  pTreeRoot->pRight->pRight = createNode(6);
  pTreeRoot->pRight->pLeft->pRight = createNode(7);
  pTreeRoot->pRight->pLeft->pRight->pLeft = createNode(9);

  pTreeRoot->pRight->pRight->pRight = createNode(8);
  pTreeRoot->pRight->pRight->pRight->pRight = createNode(10);
  pTreeRoot->pRight->pRight->pRight->pRight->pLeft = createNode(11);

  displayTree(pTreeRoot, 0);
  printf("\n");

  int d, isOdd = 1, level = 1;

//  d = depthOfDeepestOddLevel(pTreeRoot, isOdd);
  d = depthOfDeepestOddLevel(pTreeRoot, level);
  printf ("%d\n", d);
  return 0;
}
