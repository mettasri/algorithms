#include <stdio.h>
#include <limits.h>
#include <malloc.h>
 
int min(int x, int y) { return (x < y)? x: y; }
 
// Returns minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
    int *jumps = malloc(sizeof(int) * n);  // jumps[n-1] will hold the result
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                 jumps[i] = min(jumps[i], jumps[j] + 1);
                 printf("%d %d\n", i, jumps[i]);
                 break;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
      printf("%2d ", jumps[i]);
    }
    printf("\n");
    return jumps[n-1];
}
 
// Driver program to test above function
int main()
{
//    int arr[] = {1, 3, 6, 1, 0, 9};
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d \n", minJumps(arr,size));
    return 0;
}

