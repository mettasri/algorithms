#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode *pRoot = NULL;

void populateInOrdNext(TreeNode* pBase)
{
  static TreeNode *pTemp = NULL;
  if(NULL == pBase) return;

  populateInOrdNext(pBase->pRight);
  pBase->pNext = pTemp;
  printf("data = %d, next = %d\n", pBase->data, pTemp ? pTemp->data : 0);
  pTemp = pBase;
  populateInOrdNext(pBase->pLeft);
}

int main()
{
  TreeNode *pNode;

  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft= createNode(6);
  pRoot->pRight->pRight = createNode(7);

  displayTree(pRoot, 0);
  printf("\n");

  // Populates nextRight pointer in all nodes
  populateInOrdNext(pRoot);

  TreeNode *ptr = pRoot->pLeft->pLeft;
  while(ptr)
  {
    printf("%d next is %d \n", ptr->data, ptr->pNext? ptr->pNext->data: 0);
    ptr = ptr->pNext;
  }


  return 0;
}
