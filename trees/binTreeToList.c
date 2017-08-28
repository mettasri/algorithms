#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

/*
TreeNode* binTree2List(TreeNode *pBase)
{
  if(pBase->pLeft)
  {
    TreeNode *pLeftNode = binTree2List(pBase->pLeft);
    for(; pLeftNode->pRight; pLeftNode = pLeftNode->pRight);
    pLeftNode->pRight = pBase;
    pBase->pLeft = pLeftNode;
  }
  if(pBase->pRight)
  {
    TreeNode *pRightNode = binTree2List(pBase->pRight);
    for(; pRightNode->pLeft; pRightNode = pRightNode->pLeft);
    pRightNode->pLeft = pBase;
    pBase->pRight = pRightNode;
  }

  return (pBase);
}
*/

void setPrevLink(TreeNode *pBase)
{
  static TreeNode *pPrev = NULL;

  if(NULL != pBase)
  {
    setPrevLink(pBase->pLeft);
    pBase->pLeft = pPrev;
    pPrev = pBase;
    setPrevLink(pBase->pRight);
  }
}

TreeNode* setNextLink(TreeNode *pBase)
{
  TreeNode *pPrev = NULL;
  
  while(NULL != pBase->pRight)
  {
    pBase = pBase->pRight;
  }

  while(NULL != pBase->pLeft)
  {
    pPrev = pBase;
    pBase = pBase->pLeft;
    pBase->pRight = pPrev;
  }
  return pBase;
}

TreeNode* binTree2List(TreeNode *pBase)
{
  setPrevLink(pBase);
  return setNextLink(pBase);
}

/*
void binTree2List(TreeNode *pBase, TreeNode **pHead)
{
  if(NULL == pBase)  return;

  static TreeNode *pPrev = NULL;
  binTree2List(pBase->pLeft, pHead);
  if(NULL == pPrev)
    *pHead = pBase;
  else
  {
    pPrev->pRight = pBase;
    pBase->pLeft = pPrev;
  }
  pPrev = pBase;
  binTree2List(pBase->pRight, pHead);
}
*/

void displayTreeList(TreeNode *pHead)
{
  printf("List: ");
  while(NULL != pHead)
  {
    printf("%d  ", pHead->data);
    pHead = pHead->pRight;
  }
  printf("\n\n");
}

TreeNode *pRoot = NULL;

int main()
{
  TreeNode *pHead;

  pRoot = createNode(10);
  pRoot->pLeft = createNode(12);
  pRoot->pLeft->pLeft = createNode(25);
  pRoot->pLeft->pRight = createNode(30);

  pRoot->pRight = createNode(15);
  pRoot->pRight->pLeft = createNode(36);

  displayTree(pRoot, 0);
  printf("\n");

  pHead = binTree2List(pRoot);
  
  while(NULL != pHead->pLeft)
  {
    pHead = pHead->pLeft;
  }

//  binTree2List(pRoot, &pHead);
  displayTreeList(pHead);
}
