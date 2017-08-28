#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

TreeNode *pRoot;

void convertToChildSumProperty(TreeNode* pBase)
{
  if(NULL == pBase)
  {
    return;
  }
  
  convertToChildSumProperty(pBase->pLeft);
  convertToChildSumProperty(pBase->pRight);

  int left = pBase->pLeft ? pBase->pLeft->data : 0;
  int right = pBase->pRight ? pBase->pRight->data : 0;
  int diff;
  
  if(left != 0 || right != 0)
  {
    diff = left + right - pBase->data;

    if (diff > 0)
    {
      printf("data %d changed to %d \n", pBase->data, pBase->data + diff);
      pBase->data += diff;
    }
    else if (diff < 0)
    {
      if(NULL != pBase->pLeft)
      {
        printf("data %d changed to %d \n", pBase->pLeft->data, pBase->pLeft->data - diff);
        pBase->pLeft->data += -diff;
        convertToChildSumProperty(pBase->pLeft);
      }
      else if(NULL != pBase->pRight)
      {
        printf("data %d changed to %d \n", pBase->pRight->data, pBase->pRight->data - diff);
        pBase->pRight->data += -diff;
        convertToChildSumProperty(pBase->pRight);
      }
    //  printf("data = %d\n", pBase->data);
    //  displayTree(pRoot, 0);
    //  printf("\n");
    }
  }
}

int main()
{

  pRoot = createNode(80);
  pRoot->pLeft = createNode(9);
  pRoot->pLeft->pLeft = createNode(3);
  pRoot->pLeft->pLeft->pLeft = createNode(1);
  pRoot->pLeft->pLeft->pRight = createNode(1);
  pRoot->pLeft->pRight = createNode(5);

  pRoot->pRight = createNode(35);
  pRoot->pRight->pLeft = createNode(1);
  pRoot->pRight->pLeft->pLeft = createNode(10);
  pRoot->pRight->pLeft->pRight = createNode(20);
  pRoot->pRight->pRight = createNode(30);

  displayTree(pRoot, 0);
  printf("\n");


  convertToChildSumProperty(pRoot);
  displayTree(pRoot, 0);
  printf("\n");

}
