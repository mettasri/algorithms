#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode* appendList(TreeNode *pList1, TreeNode *pList2)
{
  TreeNode *temp;

  if(NULL == pList1)
  {
    return pList2;
  }
  if(NULL == pList2)
  {
    return pList1;
  }
  pList1->pLeft->pRight = pList2;
  pList2->pLeft->pRight = pList1;
  temp = pList1->pLeft;
  pList1->pLeft = pList2->pLeft;
  pList2->pLeft = temp;

  return pList1;
}

TreeNode* recursiveTreeToList(TreeNode *pBase)
{
  TreeNode *lList, *rList;

  if(NULL == pBase)
    return pBase;
  
  lList = recursiveTreeToList(pBase->pLeft);
  rList = recursiveTreeToList(pBase->pRight);

  pBase->pLeft = pBase;
  pBase->pRight = pBase;

//  printf("pBase=%d, lList=%d, rlist=%d\n", pBase? pBase->data : 0, lList ? lList->data : 0, rList ? rList->data : 0);
  lList = appendList(lList, pBase);
//  displayLeftRightCirList(lList);
  lList = appendList(lList, rList);
//  displayLeftRightCirList(lList);

  return lList;
}

int main()
{
  TreeNode *pRoot;
  TreeNode *pHead;

  pRoot = createNode(4);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(1);
  pRoot->pLeft->pRight = createNode(3);

  pRoot->pRight = createNode(5);

  displayTree(pRoot, 0);
  printf("\n");

  pHead = recursiveTreeToList(pRoot);

  displayLeftRightCirList(pHead);

  return 0;
}
