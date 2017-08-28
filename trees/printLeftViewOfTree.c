#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

void printLeftViewOfTree(TreeNode *pBase, int level, int *max_level)
{
  if(NULL == pBase) return;
  printf("data=%d l=%d max_l=%d \n", pBase->data, level, *max_level);  
  if(level > *max_level)
  {
    printf("%d\n", pBase->data);
    *max_level = level;
  }
  
  printLeftViewOfTree(pBase->pLeft,  level + 1, max_level);
  printLeftViewOfTree(pBase->pRight, level + 1, max_level);
}

TreeNode *pRoot = NULL;

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
  
  int max_level = 0;
  
  printLeftViewOfTree(pRoot, 1, &max_level);
  printf("\n");

  return 0;
}

