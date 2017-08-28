#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode* buildTreeFromSpecialPreorderSeq(int *pre, char *preLN, int len)
{
  TreeNode *pBase;
  int static index = 0;

  pBase = createNode(pre[index]);
  if('L' == preLN[index])
  {
    pBase->pLeft = NULL;
    pBase->pRight = NULL;
    index++;
    return pBase;
  }
  index++;

  pBase->pLeft  = buildTreeFromSpecialPreorderSeq(pre, preLN, len);
  pBase->pRight = buildTreeFromSpecialPreorderSeq(pre, preLN, len);

  return pBase;
}

int main()
{
  TreeNode *pRoot = NULL;
  int pre[]    = { 10,  30,  20,  5,  15,  30,   40};
  char preLN[] = {'N', 'N', 'L', 'L', 'N', 'L', 'L'};

  int len = sizeof(pre)/sizeof(pre[0]);
//  printf("len = %d\n", len);

  pRoot = buildTreeFromSpecialPreorderSeq(pre, preLN, len);

  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}

