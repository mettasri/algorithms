#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int findMax(int *in, int inStart, int inEnd)
{
  int i, pos = inStart, max = in[inStart];

  for(i = inStart + 1; i <= inEnd; i++)
  {
    if(in[i] > max)
    {
      max = in[i];
      pos = i;
    }
  }
  return pos;
}

TreeNode* buildTreeFromSpecialInorderSeq(int *in, int inStart, int inEnd)
{
  int inIndex;
  TreeNode *pBase = NULL;

  if(inStart > inEnd)
  {
    return NULL;
  }
  inIndex = findMax(in, inStart, inEnd);
  pBase = createNode(in[inIndex]);

  pBase->pLeft  = buildTreeFromSpecialInorderSeq(in, inStart, inIndex - 1);
  pBase->pRight = buildTreeFromSpecialInorderSeq(in, inIndex + 1, inEnd);

  return pBase;
}

int main()
{
  TreeNode *pRoot = NULL;
  int in[]  = {1, 5, 10, 40, 30, 15, 28, 20};

  int len = sizeof(in)/sizeof(in[0]);
//  printf("len = %d\n", len);

  pRoot = buildTreeFromSpecialInorderSeq(in, 0, len - 1);

  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}

