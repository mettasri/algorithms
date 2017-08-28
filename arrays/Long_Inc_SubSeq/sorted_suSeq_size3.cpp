#include<stdio.h>

void printIndex(int size)
{
  int i;

  for(i = 0; i < size; i++)
    printf("%3d", i);
  printf("\n");
}

void printTable(int *tailTable, int size)
{
  int i;

  for(i = 0; i < size; i++)
    printf("%3d", tailTable[i]);
  printf("\n");
}
// A function to fund a sorted subsequence of size 3
void find3Numbers(int arr[], int n)
{
  int max = n-1; //Index of maximum element from right side
  int min = 0; //Index of minimum element from left side
  int i;

  // Create an array that will store index of a smaller
  // element on left side. If there is no smaller element
  // on left side, then smaller[i] will be -1.
  int *smaller = new int[n];
  smaller[0] = -1;  // first entry will always be -1
  printf("min_i: ");
  printf("%3d", min);
  for (i = 1; i < n; i++)
  {
    if (arr[i] <= arr[min])
    {
      min = i;
      smaller[i] = -1;
    }
    else
      smaller[i] = min;
    printf("%3d", min);
  }
  printf("\n");

  printf("       ");
  printTable(smaller, n);

  // Create another array that will store index of a
  // greater element on right side. If there is no greater
  // element on right side, then greater[i] will be -1.
  int *greater = new int[n];
  greater[n-1] = -1;  // last entry will always be -1
  printf("max_i: ");
  printf("%3d", max);
  for (i = n-2; i >= 0; i--)
  {
    if (arr[i] >= arr[max])
    {
      max = i;
      greater[i] = -1;
    }
    else
      greater[i] = max;
    printf("%3d", max);
  }
  printf("\n");

  printf("       ");
  printTable(greater, n);

  // Now find a number which has both a greater number on
  // right side and smaller number on left side
  for (i = 0; i < n; i++)
  {
    if (smaller[i] != -1 && greater[i] != -1)
    {
      printf("%d %d %d", arr[smaller[i]],
          arr[i], arr[greater[i]]);
      return;
    }
  }

  // If we reach number, then there are no such 3 numbers
  printf("No such triplet found");

  // Free the dynamically alloced memory to avoid memory leak
  delete [] smaller;
  delete [] greater;

  return;
}

// Driver program to test above function
int main()
{
  int arr[] = {12, 11, 10, 5, 6, 2, 30};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("       ");
  printIndex(n);
  printf("       ");
  printTable(arr, n);
  printf("\n");
  find3Numbers(arr, n);
  return 0;
}
