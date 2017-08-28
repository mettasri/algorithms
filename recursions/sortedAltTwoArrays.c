#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%2d ", arr[i]);
  printf("\n");
}

int getNextMaxIndex(int A[], int m, int res[], int index, int *max_i)
{
  if(index == 0)
    return 1;

  int i;
  for(i = *max_i; i < m; i++) {
    if(res[index - 1] < A[i]) {
      *max_i = i;
      return 1;
    }
  }
  return 0;
}

void generate(int A[], int B[], int m, int n, int res[], int index)
{
  if(index !=0 && index % 2 == 0) {
    printArr(res, index);
  }

  int i;
  for(i = 0; i < m; i++) {
    if(!getNextMaxIndex(A, m, res, index, &i))
      return;

    res[index] = A[i];
    generate(B, A, n, m, res, index + 1);
  }
  return;
}


// Driver program
int main()
{
//  int A[] = {10, 15, 25};
//  int B[] = {1, 5, 20, 30};
  int A[] = {  10, 15,    25,   35,           80, 90};
  int B[] = {5,        20,   30,   40, 60, 70};  
  int res[10] = {0};
  int m = sizeof(A)/sizeof(A[0]);
  int n = sizeof(B)/sizeof(B[0]);
  generate(A, B, m, n, res, 0);
  return 0;
}
