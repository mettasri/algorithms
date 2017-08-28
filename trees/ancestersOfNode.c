#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int ancestersOfNode(TreeNode *pBase, int data)
{
//  printf("  %d  ", pBase ? pBase->data : 0);
  if(NULL == pBase)
    return 0;
  else if(data == pBase->data)
  {
    return 1;
  }

  if(ancestersOfNode(pBase->pLeft, data) || ancestersOfNode(pBase->pRight, data))
  {
    printf("%d ", pBase->data);
    return 1;
  }
  return 0;
}

void ancesterIterative(TreeNode *pBase, int data)
{
  StackNode *pStack = NULL;
  TreeNode *pTemp;

  do
  {
    /* quit */
    if(pBase && pBase->data == data)
    {
      break;
    }
    /* push until leaf node */
    if(NULL != pBase)
    {
      push(&pStack, pBase);
//      printf("push : %d\n", pBase->data);
      pBase = pBase->pLeft ? pBase->pLeft : pBase->pRight;
    }
    else /* pop until a new right node */
    {
      do
      {
        pTemp = pop(&pStack);
//        printf("pop: %d \n", pTemp->data);
        pBase = isStackEmpty(&pStack) ? NULL : topOfStack(&pStack)->pRight;
//        printf("top right : %d \n", pBase ? pBase->data: 0);
      }while((pBase && pBase == pTemp));
    }
  }while(!isStackEmpty(&pStack));
  
  while(!isStackEmpty(&pStack))
  {
    printf("%d ", pop(&pStack)->data);
  }
}

int main()
{
  int data;
  TreeNode *pT;

  pT = createNode(1);
  pT->pLeft = createNode(2);
  pT->pLeft->pLeft = createNode(4);
  pT->pLeft->pRight = createNode(5);
  pT->pLeft->pLeft->pLeft = createNode(8);
  pT->pLeft->pRight->pRight = createNode(9);

  pT->pRight = createNode(3);
  pT->pRight->pLeft = createNode(6);
  pT->pRight->pRight = createNode(7);
  pT->pRight->pRight->pLeft = createNode(10);

  displayTree(pT, 0);
  printf("\n\n");
  
  int i;
  for(i = 1; i <= 11; i++)
  {
    printf("ancestor of %2d: ", i);
//    ancestersOfNode(pT, i);
    ancesterIterative(pT, i);
    printf("\n");
  }
  return 0;
}

