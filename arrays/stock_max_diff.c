#include <stdio.h>

int stockDiff(int arr[], int size)
{
  int i;
  int min = arr[0];
  int maxDiff = 0;

  for(i = 1; i < size; i++)
  {
    if(min > arr[i])
      min = arr[i];
    if(maxDiff < arr[i] - min)
      maxDiff = arr[i] - min;
  }
  return (maxDiff);
}

int main()
{
  int arr[] = {2, 3, 10, 20, 4, 8, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("%d\n", stockDiff(arr, size));
}
