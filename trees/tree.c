#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int size (TreeNode *pBase)
{
  if (pBase == NULL) 
    return 0;
  else    
    return(size(pBase->pLeft) + 1 + size(pBase->pRight));  
}

int max1(int x, int y)
{
  return ((x > y) ? (x + 1) : (y + 1));
}

int maxDepth(TreeNode *pBase)
{
  if(pBase == NULL)
  {
    return 0;
  }
  return max1(maxDepth(pBase->pRight), 
             maxDepth(pBase->pLeft));
}

void mirrorOfTree(TreeNode* pBase)
{
  TreeNode* temp;

  if(NULL == pBase)
  {
    return;
  }
  mirrorOfTree(pBase->pLeft);
  mirrorOfTree(pBase->pRight);

  temp = pBase->pLeft;
  pBase->pLeft = pBase->pRight;
  pBase->pRight = temp;
//  printf("pBase left, right = %X  %X\n", pBase->pLeft, pBase->pRight);
}

void rootToLeafPath(TreeNode* pBase, int height)
{
  int static arr[10] = {0};
  int i = 0;

  if(NULL == pBase)
  {
    return;
  }
  arr[height] = pBase->data;
  rootToLeafPath(pBase->pLeft, height + 1);
  rootToLeafPath(pBase->pRight, height + 1);
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    for(i = 0; i <= height; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }
}

int isChildrenSumProperty(TreeNode* pBase)
{
  if(NULL == pBase)
  {
    return 1;
  }
  if((NULL == pBase->pLeft) && (NULL == pBase->pRight))
  {
    return 1;
  }
  
  if(isChildrenSumProperty(pBase->pLeft) && isChildrenSumProperty(pBase->pRight) &&
     (pBase->data == ((pBase->pLeft ? pBase->pLeft->data : 0) + (pBase->pRight ? pBase->pRight->data : 0)))
    )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


void incLeftChildForChildSumProperty(TreeNode* pBase)
{
  int diff;

  if(NULL == pBase)
  {
    return;
  }
  else if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return;
  }

  diff = pBase->data - ((pBase->pLeft ? pBase->pLeft->data : 0) + (pBase->pRight ? pBase->pRight->data : 0));
  if(diff)
  {
    pBase->pLeft ? (pBase->pLeft->data += diff) : (pBase->pRight ? pBase->pLeft->data += diff: 0);
  }
  incLeftChildForChildSumProperty(pBase->pLeft);
  incLeftChildForChildSumProperty(pBase->pRight);
}

void convertToChildSumProperty(TreeNode* pBase)
{
  int diff;
  
  if(NULL == pBase)
  {
    return;
  }
  else if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return;
  }
  
  convertToChildSumProperty(pBase->pLeft);
  convertToChildSumProperty(pBase->pRight);

  diff = ((pBase->pLeft ? pBase->pLeft->data : 0) + (pBase->pRight ? pBase->pRight->data : 0)) - pBase->data;
  if (0 < diff)
  {
    printf("data %d changed to %d \n", pBase->data, pBase->data + diff);
    pBase->data += diff;
  }
  else if (0 > diff)
  {
    printf("diff=%X\n", diff);
    incLeftChildForChildSumProperty(pBase);
  }
}

 
int height(TreeNode* node)
{
   if(node == NULL)
       return 0;
 
   return 1 + max(height(node->pLeft), height(node->pRight));
} 

int pathSumEqToNum(TreeNode* pBase, int sum)
{
  if(NULL == pBase)
  {
    return 0;
  }

//  int subSum = sum - pBase->data;
  if(NULL == pBase->pLeft && NULL == pBase->pRight)
  {
    return (sum - pBase->data == 0) ? 1 : 0;
  }
  return (pathSumEqToNum(pBase->pLeft, sum - pBase->data) || pathSumEqToNum(pBase->pRight, sum - pBase->data));
}

void changedToDoubleTree(TreeNode* pBase)
{
  TreeNode *pTemp;

  if(NULL == pBase)
  {
    return;
  }

  changedToDoubleTree(pBase->pLeft);
  changedToDoubleTree(pBase->pRight);

  pTemp = pBase->pLeft;
  pBase->pLeft = createNode(pBase->data);
  pBase->pLeft->pLeft = pTemp;
}

int treeHeight(TreeNode* pBase)
{
  if(NULL == pBase)
  {
    return 0;
  }

  return (1 + max(treeHeight(pBase->pLeft), treeHeight(pBase->pRight)));
}

int levelWidth(TreeNode* pBase, int level)
{
  if(0 == level) return 0;
  if(NULL == pBase) return 0;
  if(1 == level) return 1;
    
  return (levelWidth(pBase->pLeft, level - 1) + levelWidth(pBase->pRight, level - 1));
}

int getMaxWidth(TreeNode* pBase)
{
  int i, h, subWidth, maxWidth = 0;

  h = treeHeight(pBase);
  printf("height = %d \n", h);

  for (i = 1; i <= h; i++)
  {
    subWidth = levelWidth(pBase, i);
    if(maxWidth < subWidth)
      maxWidth = subWidth;
    printf("height = %d, subWidth = %d, maxWidth=%d \n", i, subWidth, maxWidth);
  }
  return maxWidth;
}

int levelOfNode(TreeNode* pBase, int data)
{
  int l;

  if(NULL == pBase) return 0;
  if(data == pBase->data) return 1;

  if((l = levelOfNode(pBase->pLeft, data)) || (l = levelOfNode(pBase->pRight, data)))
  {
//    printf("data = %d l = %d \n", pBase->data, l);
    return (l + 1);
  }
}

int ancestorsOfNode(TreeNode *pBase, int data)
{
  int l;

  if(NULL == pBase) return 0;
  if(data == pBase->data) return 1;
  
  if(ancestorsOfNode(pBase->pLeft, data) || ancestorsOfNode(pBase->pRight, data))
  {
    printf("%d\n", pBase->data);
    return 1;
  }
  return 0;
}

int sumTree(TreeNode *pBase)
{
  int ld, rd, sum;

  if(NULL == pBase) return 0;
  if((NULL == pBase->pLeft) && (NULL == pBase->pRight)) return pBase->data;

  ld = sumTree(pBase->pLeft);
  rd = sumTree(pBase->pRight);
  sum = ld + rd;
  printf("data = %d ld=%d rd=%d sum=%d \n", pBase->data, ld, rd, sum);

  return ((sum == pBase->data) ? (sum + pBase->data) : 0);
}

TreeNode *pRoot = NULL;

int main()
{
  int data, ch;
  TreeNode *pNode;

  
  pRoot = createNode(26);
  pRoot->pLeft = createNode(10);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(6);

  pRoot->pRight = createNode(3);
  pRoot->pRight->pRight = createNode(3);

/*
// Level of a node
  pRoot = createNode(10);

  pRoot->pLeft = createNode(7);
  pRoot->pLeft->pRight = createNode(9);
  
  pRoot->pRight = createNode(15);
  pRoot->pRight->pLeft = createNode(11);
*/
/*
// Root to leaf path sum equal to a given number
  pRoot = createNode(10);

  pRoot->pLeft = createNode(8);
  pRoot->pLeft->pLeft = createNode(3);
  pRoot->pLeft->pRight = createNode(5);
  
  pRoot->pRight = createNode(2);
  pRoot->pRight->pLeft= createNode(2);
*/
/*
// Is height-balanced tree
  pRoot = createNode(1);

  pRoot->pLeft = createNode(2);
  pRoot->pLeft->pLeft = createNode(4);
  pRoot->pLeft->pRight = createNode(5);
  pRoot->pLeft->pRight->pLeft = createNode(7);
//  pRoot->pLeft->pRight->pLeft->pLeft = createNode(8);
  
  pRoot->pRight = createNode(3);
  pRoot->pRight->pRight = createNode(6);
*/




/*
  pRoot->pLeft->pLeft->pLeft = createNode(8);
  pRoot->pLeft->pLeft->pRight = createNode(9);
  pRoot->pLeft->pRight->pLeft = createNode(10);
  pRoot->pLeft->pRight->pRight = createNode(11);
  pRoot->pRight->pLeft->pLeft = createNode(12);
  pRoot->pRight->pLeft->pRight = createNode(13);
  pRoot->pRight->pRight->pLeft = createNode(14);
  pRoot->pRight->pRight->pRight = createNode(15);

  pRoot->pRight->pRight->pLeft->pLeft = createNode(16);
  pRoot->pRight->pRight->pLeft->pRight = createNode(17);
*/
  displayTree(pRoot, 0);
  printf("\n");

  while (1)
  {
    printf("1.Insert 2.MirrorOfTree 3.RootToLeafPath 4.IsChildrenSumProperty \
5.convertToChildSumProperty 8.pathSumEqToNum \
9.changedToDoubleTree 10.getMaxWidth 11.levelOfNode 12.ancestorsOfNode 13.sumTree 14.Exit \n"); 
    printf("Enter choice: "); scanf("%d", &ch);
    switch(ch)
    {
      case 1:
        printf("Enter node: "); scanf("%d", &data);
        pNode = createNode(data);

        //  insertNodeIntoTree(pRoot, pNode);
        insertNodeIntoTree(&pRoot, pNode);
//        printf("pRoot=%X\n", pRoot);

        displayTree(pRoot, 0);
        printf("\n");
        break;

      case 2:
        mirrorOfTree(pRoot);
        displayTree(pRoot, 0);
        printf("\n");
        break;

      case 3:
        rootToLeafPath(pRoot, 0);
        break;
        
      case 4:
        if(1 == isChildrenSumProperty(pRoot))
        {
          printf("Children Sum Property satisfied \n\n");
        }
        else
        {
          printf("Children Sum Property not satisfied \n\n");
        }
        break;

      case 5:
        convertToChildSumProperty(pRoot);
        displayTree(pRoot, 0);
        printf("\n");
        break;

      case 6:
        break;

      case 7:
        break;
      
      case 8:
        printf("Enter the num: "); scanf("%d", &data);
        if(1 == pathSumEqToNum(pRoot, data))
        {
          printf("Present \n\n");
        }
        else
        {
          printf("not present \n\n");
        }
        break;

      case 9:
        changedToDoubleTree(pRoot);
        displayTree(pRoot, 0);
        printf("\n");
        break;

      case 10:
        printf("Max Width = %d \n", getMaxWidth(pRoot));
        break;

      case 11:
        printf("Enter the num: "); scanf("%d", &data);
        printf("Level of node = %d is %d \n", data, levelOfNode(pRoot, data));
        break;

      case 12:
        printf("Enter the num: "); scanf("%d", &data);
        ancestorsOfNode(pRoot, data);
        break;

      case 13:
        if(0 != sumTree(pRoot))
        {
          printf("Sum Tree \n\n");
        }
        else
        {
          printf("not Sum Tree\n\n");
        }
        break;

      case 14:  
        exit(0);
        break;

      default:
        break;
    }
/*    printf("size = %d \n", size(pRoot));
    printf("max depth = %d \n\n", maxDepth(pRoot));
*/  
  }
  return 0;
}
