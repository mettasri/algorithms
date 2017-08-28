#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

  static int arr[10] = {0};
  static int index = 0;

int verticalSum(TreeNode *pBase, int hd)
{
  if(NULL == pBase)  return 0;
  verticalSum(pBase->pLeft, hd - 1);
  if(index > hd)
  {
    printf("index=%d, hd=%d\n", index, hd);
    index = hd;
  }
  printf("index=%d, hd=%d\n", index, hd);
  arr[hd + (-index)] += pBase->data;
  verticalSum(pBase->pRight, hd + 1);
}

TreeNode *pRoot = NULL;

int main()
{
  int i;
  TreeNode *pNode;

  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);

  displayTree(pRoot, 0);
  printf("\n");

  verticalSum(pRoot, 0);
  for(i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
