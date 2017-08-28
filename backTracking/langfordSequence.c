#include <stdio.h>

void printArray(int arr[], int size, int indent)
{
  int i;

  printf("%*d: ", indent*2, indent);
  for(i = 0; i < size; i++) {
    printf("%2d", arr[i]);
  }
  printf("\n");
}

void langfordSeries(int arr[], int size, int n)
{
  if(n == 0) {
    printArray(arr, size, 0);
    return;
  }

  int i;
  for(i = 0; i <  size - n - 1; i++) {
    if(arr[i] == 0 && arr[i + n + 1] == 0) {
      arr[i] = arr[i + n + 1] = n;
//      printArray(arr, size, n);
      langfordSeries(arr, size, n - 1);
      arr[i] = arr[i + n + 1] = 0;
//      printArray(arr, size, n);
    }
  }
  return;
}

int main()
{
  int arr[100] = {0};
  int n = 7;
  langfordSeries(arr, 2*n, n);
}
