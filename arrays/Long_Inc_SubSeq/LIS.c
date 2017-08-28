/* A Naive recursive implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>

/* To make use of recursive calls, this function must return two things:
   1) Length of LIS ending with element arr[n-1]. We use max_ending_here 
   for this purpose
   2) Overall maximum as the LIS may end with an element before arr[n-1] 
   max_ref is used this purpose.
   The value of LIS of full array of size n is stored in *max_ref which is our final result
   */
int lis( int arr[], int list[], int n, int ind)
{
#ifdef DP
  if(list[n-1])
    return (list[n-1]);
#endif

  int i, res, max_ending_here = 1; // length of LIS ending with arr[n-1]

  /* Recursively get all LIS ending with arr[0], arr[1] ... ar[n-2]. If 
     arr[i-1] is smaller than arr[n-1], and max ending with arr[n-1] needs
     to be updated, then update it */
  for(i = 1; i < n; i++)
  {
    printf("%*d\n", ind, i);
    res = lis(arr, list, i, ind+2);
    if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
      max_ending_here = res + 1;
  }
  
#ifdef DP  
  list[n-1] = max_ending_here;
  printf("list[%d-1]: %d\n", n, list[n-1]);
#endif
  // Compare max_ending_here with the overall max. And update the
  // overall max if needed
  // Return length of LIS ending with arr[n-1]
#ifdef DP  
  return (list[n-1]);
#else
  return max_ending_here;
#endif
}

/* Driver program to test above function */
int main()
{
//  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 85 };
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  int *list = calloc(n, sizeof(int));

  printf("Length of LIS is %d\n",  lis( arr, list, n, 1));

#ifdef DP  
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%3d", list[i]);
  }
  printf("\n");
#endif
  free(list);
  return 0;
}
