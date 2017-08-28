#include <stdio.h>
#include <stdlib.h>
#include "tree_utils.h"

TreeNode *pT = NULL;
TreeNode *pS = NULL;

int isStEqToBt(TreeNode* pT, TreeNode* pS)
{
  if(NULL == pT && NULL == pS) return 1;
  else if (NULL == pT || NULL != pS)
    return 0;
  return(pT->data == pS->data && isStEqToBt(pT->pLeft, pS->pLeft) && isStEqToBt(pT->pLeft, pS->pLeft));
}

int isSubTreeInBinaryTree(TreeNode* pT, TreeNode* pS)
{
  if(NULL == pT) return 1;
  if(NULL == pS) return 0;

  if(isStEqToBt(pT, pS)) return 1;
  
  return(isSubTreeInBinaryTree(pT->pLeft, pS) || isSubTreeInBinaryTree(pT->pRight, pS));
}

int main()
{
  pT = createNode(26);
  pT->pLeft = createNode(10);
  pT->pLeft->pLeft = createNode(4);
  pT->pLeft->pRight = createNode(6);
  pT->pLeft->pLeft->pRight = createNode(30);

  pT->pRight = createNode(3);
  pT->pRight->pRight = createNode(3);

  pS = createNode(10);
  pS->pLeft = createNode(4);
  pS->pLeft->pRight = createNode(30);

  pS->pRight = createNode(6);

  displayTree(pT, 0);
  printf("\n\n");
  displayTree(pS, 0);
  printf("\n\n");

  if(1 == isSubTreeInBinaryTree(pT, pS))
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }
  printf("\n\n");

  return 0;
}
