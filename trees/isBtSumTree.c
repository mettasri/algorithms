#include <stdio.h>
#include <stdlib.h>
#include "tree_utils.h"

TreeNode *pRoot = NULL;

int getLRd(TreeNode *pBase)
{
  if(NULL == pBase) return 0;
  else if(NULL == pBase->pLeft && NULL == pBase->pRight) return pBase->data;
  else return 2 * pBase->data;
}

int isBtSumTree(TreeNode *pBase)
{
  int ld, rd;

  if(NULL == pBase) return 1;
  if((NULL == pBase->pLeft) && (NULL == pBase->pRight)) return 1;

  if(isBtSumTree(pBase->pLeft) && isBtSumTree(pBase->pRight))
  {
    ld = getLRd(pBase->pLeft);
    rd = getLRd(pBase->pRight);
    printf("data = %d ld=%d rd=%d \n", pBase->data, ld, rd);
    return ((ld + rd) == pBase->data);
  }
}

int main()
{
  TreeNode *pNode;

  pRoot = createNode(26);
  pRoot->pLeft = createNode(10);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(6);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pRight = createNode(3);

  displayTree(pRoot, 0);
  printf("\n");

  if(0 != isBtSumTree(pRoot))
  {
    printf("Binary Sum Tree \n\n");
  }
  else
  {
    printf("not Binary Sum Tree\n\n");
  }

  return 0;
}
