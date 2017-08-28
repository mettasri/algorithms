// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
  int i, j, isSwap = 0;
  for (i = 0; i < n-1; i++)      
  {
    isSwap = 0;
    for (j = 0; j < n-i-1; j++) //Last i elements are already in place  
    {
      if (arr[j] > arr[j+1])
      {
        isSwap = 1;
        swap(&arr[j], &arr[j+1]);
      }
    }
    if(!isSwap) /* array is sorted already */
      break;
    printArray(arr, n);
  }
}


// Driver program to test above functions
int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
//  int arr[] = {11, 12, 22, 25, 34, 64, 90};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
