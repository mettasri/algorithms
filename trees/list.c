#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int main()
{
  int ch;
  ListNode *pHead = NULL;

  while(1)
  {
    printf("1.Add 2.Del 3.display: "); scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        printf("Enter data: "); scanf("%d", &ch);
        insertLastInList(&pHead, createListNode(ch));
        displayList(pHead);
        break;
      
      case 2:
        printf("Enter data: "); scanf("%d", &ch);
        deleteFromList(&pHead, ch);
        displayList(pHead);
        break;
     
      case 3:
        displayList(pHead);
        break;
    }
  }
}
