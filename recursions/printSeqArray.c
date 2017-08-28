#include <stdio.h>

void printArray(int arr[], int len)
{
  int i;

  for(i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void printSeq(int arr[], int start, int end, int temp[], int ix, int r)
{
  if(ix == r)
  {
    printArray(temp, ix);
    return;
  }
  int i;
  for(i = start; i < end && end-i >= r-ix; i++)
  {
    temp[ix] = arr[i];
    printSeq(arr, i + 1, end, temp, ix + 1, r);
  }
}

int main ()
{
  int arr[] = {1, 2, 3, 4};
  int temp[2] = {0};
  int len = sizeof(arr)/sizeof(arr[0]);
  int r = 2, ix = 0;

  printSeq(arr, 0, len, temp, ix, r);

  return 0;
}
