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

TreeNode* buildTreeFromPrePostorderSeq(char *pre, char *post, int postStart, int postEnd)
{
  static int preIndex = 0;
  TreeNode *pBase = NULL;

  printf("%d -> %d, %d\n", pre[preIndex], postStart, postEnd);

  pBase = createNode(pre[preIndex++]);
  if(postStart > postEnd)
    return (pBase);

  int postLeftPos  = findPosition(post, postStart, postEnd, pre[preIndex]);
  pBase->pLeft  = buildTreeFromPrePostorderSeq(pre, post, postStart, postLeftPos - 1);
  int postRightPos = findPosition(post, postStart, postEnd, pre[preIndex]);
  pBase->pRight = buildTreeFromPrePostorderSeq(pre, post, postLeftPos + 1, postRightPos - 1);

  return pBase;
}

int main()
{
  TreeNode *pRoot = NULL;
//  char pre[]  = {1, 2, 3, 4, 5, 6, 7};
//  char post[] = {2, 4, 6, 7, 5, 3, 1};

  char pre[]  = {1, 2, 4, 8, 9, 5, 3, 6, 7};
  char post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

//  char pre[]  = {1, 2, 4, 5, 3, 6, 7};
//  char post[] = {4, 5, 2, 6, 7, 3, 1};

  int len = sizeof(pre)/sizeof(pre[0]);
//  printf("len = %d\n", len);

  pRoot = buildTreeFromPrePostorderSeq(pre, post, 0, len - 2);

  displayTree(pRoot, 0);
  printf("\n");

  return 0;
}

