#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int diameterTree(TreeNode *tree, int *height)
{
  int lh, rh, d;
  if (tree == NULL)
  {
    *height = 0;
    return 0;
  }
 
  int lD = diameterTree(tree->pLeft, &lh);
  int rD = diameterTree(tree->pRight, &rh);
  *height = (lh > rh) ? lh + 1 : rh + 1;
//  printf("height Node=%d is %d \n", tree->data, *height);
//  printf("DIAMET node=%d, l=%d, r=%d \n", tree->data, ldiameter, rdiameter);

  d = max(lh + rh + 1, max(lD, rD));
  return d;
} 

int diameter(TreeNode* tree)
{
  /* base case where tree is empty */
  if (tree == 0)
    return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(tree->pLeft);
  int rheight = height(tree->pRight);
//  printf("height Node=%d is %d \n", tree->data, lheight + rheight + 1);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->pLeft);
  int rdiameter = diameter(tree->pRight);
//  printf("DIAMET node=%d, l=%d, r=%d \n", tree->data, ldiameter, rdiameter);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 
 
int height(TreeNode* node)
{
   if(node == NULL)
       return 0;
 
   return 1 + max(height(node->pLeft), height(node->pRight));
} 

int main()
{
  TreeNode *pRoot = NULL;
  int h = 0;
//  diameter of a tree
  pRoot = createNode(1);

  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pLeft->pLeft = createNode(6);
  pRoot->pLeft->pLeft->pLeft->pLeft = createNode(7);
  pRoot->pLeft->pRight = createNode(5);
  pRoot->pLeft->pRight->pLeft = createNode(8);
  pRoot->pLeft->pRight->pRight = createNode(9);
  pRoot->pLeft->pRight->pRight->pLeft = createNode(12);
  pRoot->pLeft->pRight->pRight->pLeft->pLeft = createNode(14);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);
  pRoot->pRight->pRight->pLeft = createNode(10);
  pRoot->pRight->pRight->pRight = createNode(11);
  pRoot->pRight->pRight->pLeft->pRight = createNode(13);
  pRoot->pRight->pRight->pLeft->pRight->pRight = createNode(15);
  pRoot->pRight->pRight->pLeft->pRight->pRight->pLeft = createNode(16);
  
  displayTree(pRoot, 0);
  printf("\n");

//  printf("diameter = %d \n", diameter(pRoot));
  printf("diameter = %d \n", diameterTree(pRoot, &h));
} 
