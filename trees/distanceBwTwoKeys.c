#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int distanceBetweenTwoKeys(TreeNode *pBase, int level, int k1, int k2, int *isK1, int *isK2)
{
  if(NULL == pBase)  return 0;

  int l = 0, r = 0, c = 0;

  l = distanceBetweenTwoKeys(pBase->pLeft, level + 1, k1, k2, isK1, isK2);
  r = distanceBetweenTwoKeys(pBase->pRight, level + 1, k1, k2, isK1, isK2);
  printf("%d %d %d\n", pBase->data, l, r);

  if(!(*isK1 && *isK2))
  {
    if(k1 == pBase->data)
    {
      *isK1 = 1;
      return level;
    }
    if(k2 == pBase->data)
    {
      *isK2 = 1;
      return level;
    }
    if(l && r)
      return (l + r - (2 * level));
  }
}


int main()
{
  TreeNode *pRoot = NULL;

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
  
  while(1)
  {
    int k1, k2, isK1 = 0, isK2 = 0;

    printf("Enter K1, K2: "); scanf("%d %d", &k1, &k2);
    printf("distance: %d\n", distanceBetweenTwoKeys(pRoot, 1, k1, k2, &isK1, &isK2));
  }

  return 0;
}

