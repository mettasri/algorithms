// C++ program to print postorder traversal from preorder and inorder traversals
#include <stdio.h> 
// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n)
{
  int i;
    for (i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}
 
// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
   // The first element in pre[] is always root, search it
   // in in[] to find left and right subtrees
   printf("%d %d %d\n", in[0], pre[0], n);
   int root = search(in, pre[0], n);
 
   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostOrder(in, pre+1, root);
 
   printf("\n");
   // If right subtree is not empty, print right subtree
   if (root != n-1)
      printPostOrder(in+root+1, pre+root+1, n-root-1);
 
   // Print root
   printf("  %d \n", pre[0]);
}
 
// Driver program to test above functions
int main()
{
   int in[]  = {8, 4, 2, 5, 9, 1, 6, 3, 10, 7};
   int pre[] = {1, 2, 4, 8, 5, 9, 3, 6, 7, 10};
   int n = sizeof(in)/sizeof(in[0]);
   printf("Postorder traversal \n");
   printPostOrder(in, pre, n);
   return 0;
}
