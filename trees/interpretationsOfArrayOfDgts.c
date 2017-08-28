#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_utils.h"

static char *pDigit2AlphaMap[] = 
      {" ", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
       "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
      };

TreeNode *createAlphaTreeNode(char *pStr)
{
  TreeNode *pTemp = (TreeNode *)malloc(sizeof(TreeNode));
  strcpy(pTemp->str, pStr);
  pTemp->pLeft = NULL;
  pTemp->pRight = NULL;

//  printf("newNode data=%d, @ %X\n", pTemp->data, pTemp);
  return (pTemp);
}

TreeNode* createTreeForDigits(char *pStr, int *pArr, int size)
{
  TreeNode *pBase = createAlphaTreeNode(pStr);

  if(size > 0)
  {
    char lStr[8] = {'\0'};
    char rStr[8] = {'\0'};
    int lDigit = pArr[0];
    int rDigit = (10*pArr[0]) + pArr[1];
  
    if(lDigit <= 26)
    {
      strcpy(lStr, pBase->str);
      strcat(lStr, pDigit2AlphaMap[lDigit]);
//      printf("str:%s, lD=%d, L:%s \n", (*pBase)->str, lDigit, lStr);
      pBase->pLeft = createTreeForDigits(lStr, pArr + 1, size - 1);
    }

    if(size >= 2 && rDigit <= 26)
    {
      strcpy(rStr, pBase->str);
      strcat(rStr, pDigit2AlphaMap[rDigit]);
//      printf("str:%s, rD=%d, R:%s \n", (*pBase)->str, rDigit, rStr);
      pBase->pRight = createTreeForDigits(rStr, pArr + 2, size - 2);
    }
  }
  return pBase;
}

void displayAlphaTree(TreeNode *pBase, int spaces)
{
  int i = 0;

  if(pBase == NULL)
  {
    return;
  }
  displayAlphaTree(pBase->pRight, spaces + 1);
  for(i = 0; i < spaces; i++)
    printf("   ");
  printf("%s\n", pBase->str);
  displayAlphaTree(pBase->pLeft, spaces + 1);
}

void printLeafs(TreeNode *pBase)
{
  if(NULL == pBase)  return;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
    printf("%s ", pBase->str);

  printLeafs(pBase->pLeft);
  printLeafs(pBase->pRight);
}

void printAllInterpretations(int *pArr, int size)
{
  TreeNode *pRoot = NULL;

  pRoot = createTreeForDigits("", pArr, size);
  displayAlphaTree(pRoot, 0);
  printf("\n");
  printLeafs(pRoot);
  printf("\n\n");
}


int main()
{
  int arr1[] = {1, 2, 1};

  printAllInterpretations(arr1, sizeof(arr1)/sizeof(int));

  int arr2[] = {1, 1, 3, 4};

  printAllInterpretations(arr2, sizeof(arr2)/sizeof(int));


  return 0;
}
