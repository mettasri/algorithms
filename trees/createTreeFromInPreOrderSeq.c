#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int findPosition(char *arr, int inStart, int inEnd, int k)
{
  int i;

  for(i = inStart; i <= inEnd; i++)
  {
    if(arr[i] == k)
      return i;
  }
}

TreeNode* buildTreeFromInPreorderSeq(char *in, char *pre, int inStart, int inEnd)
{
  static int preIndex = 0;
  TreeNode *pBase = NULL;

  if(inStart > inEnd)
  {
    return NULL;
  }
  pBase = createNode(pre[preIndex++]);
//  if(inStart == inEnd)
//  {
//    printf("return %c\n", pBase->data);
//    return pBase;
//  }
  int inIndex = findPosition(in, inStart, inEnd, pBase->data);

  pBase->pLeft  = buildTreeFromInPreorderSeq(in, pre, inStart, inIndex - 1);
  pBase->pRight = buildTreeFromInPreorderSeq(in, pre, inIndex + 1, inEnd);

  printf("%c\n", pBase->data);
  
  return pBase;
}

int main()
{
  TreeNode *pRoot = NULL;
  char in[]  = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};

  int len = sizeof(in)/sizeof(in[0]);
//  printf("len = %d\n", len);

  pRoot = buildTreeFromInPreorderSeq(in, pre, 0, len - 1);

  displayTreeCharData(pRoot, 0);
  printf("\n");

  return 0;
}

