#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int LISS(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int size_excl = LISS(root->pLeft) + LISS(root->pRight);

  int size_incl = 1;
  if (root->pLeft)
    size_incl += LISS(root->pLeft->pLeft) + LISS(root->pLeft->pRight);
  if (root->pRight)
    size_incl += LISS(root->pRight->pLeft) + LISS(root->pRight->pRight);

  printf("data=%d, size_incl=%d, size_excl=%d \n", root->data, size_incl, size_excl);

  return max(size_incl, size_excl);
}

int main()
{
  TreeNode *pRoot;
  pRoot = createNode(20);
  
  pRoot->pLeft = createNode(8);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(12);
  pRoot->pLeft->pRight->pLeft = createNode(10);
  pRoot->pLeft->pRight->pRight = createNode(14);
  pRoot->pRight = createNode(22);
  pRoot->pRight->pLeft = createNode(23);
  pRoot->pRight->pRight = createNode(25);

  displayTree(pRoot, 0);
  printf("\n");

  printf ("Size of the Largest Independent Set is %d \n", LISS(pRoot));
  return 0;
}
