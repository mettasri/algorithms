#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_utils.h"

#define MAX_Q_SIZE 500


bool isCompleteBT(TreeNode* root)
{
  // Base Case: An empty tree is complete Binary Tree
  if (root == NULL)
    return true;

  QueueNode *queue = createQueue(MAX_Q_SIZE);

  bool flag = false;

  enQueue(queue, root);
  while(!isQueueEmpty(queue))
  {
    TreeNode *temp_node = deQueue(queue);
    printf("dequeue data=%d\n", temp_node->data);

    if(temp_node->pLeft)
    {
      if (flag == true)
        return false;

      printf("enqueue Left data=%d\n", temp_node->data);
      enQueue(queue, temp_node->pLeft);
    }
    else
    {
      flag = true;
      printf("%d no left flag=%d\n", temp_node->data, flag);
    }

    if(temp_node->pRight)
    {
      if(flag == true)
        return false;

      printf("enqueue Right data=%d\n", temp_node->data);
      enQueue(queue, temp_node->pRight);
    }
    else 
    {
      flag = true;
      printf("%d no right flag=%d\n", temp_node->data, flag);
    }
  }

  return true;
}

int main()
{
  TreeNode *pRoot = NULL;

  pRoot = createNode(1);
  pRoot->pLeft = createNode(2);
//  pRoot->pLeft->pLeft = createNode(4);
//  pRoot->pLeft->pRight = createNode(5);

  pRoot->pRight = createNode(3);
//  pRoot->pRight->pLeft = createNode(6);
  pRoot->pRight->pRight = createNode(7);

  displayTree(pRoot, 0);
  printf("\n");

  if(isCompleteBT(pRoot))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
