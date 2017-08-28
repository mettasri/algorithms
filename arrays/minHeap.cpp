#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void fillMatrix(int *a, int i, int n, int mat[][10], int *x, int y)
{
  if(i > n) {
    (*x) += 1;
    return;
  }

  mat[*x][y] = a[i];
  fillMatrix(a, 2*i+2, n, mat, x, y+1);
  fillMatrix(a, 2*i+1, n, mat, x, y+1);
}

void displayHeapTree(int *a, int n)
{
  int x = 0;
  int mat[n][10];

  memset(mat, 0xFF, sizeof(mat));
  fillMatrix(a, 0, n - 1, mat, &x, 0);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n/2; j++) {
      if(mat[i][j] == -1)
        cout << setw(4) << " ";
      else
        cout << setw(4) << mat[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void swap(int &x, int &y) 
{
  int temp = x;
  x = y;
  y = temp;
}

void minHeapify(int *a, int n, int i)
{
  int lc = 2*i + 1;
  int rc = 2*i + 2;
  int small = i;

  if(lc < n && a[lc] < a[small])
    small = lc;

  if(rc < n && a[rc] < a[small])
    small = rc;

  if(small != i)  {
    swap(a[small], a[i]);
    minHeapify(a, n, small);
  }
}

int getMin(int *a, int *n)
{
  int min = a[0];

  swap(a[0], a[*n-1]);
  *n -= 1;
  minHeapify(a, *n, 0);

  return min;
}

void insertKey(int *a, int *n, int key)
{
  *n = *n + 1;
  int i = *n - 1;
  a[i] = key;

  int parent = (i - 1) / 2;
  while(i != 0 && a[parent] > a[i]) {
    swap(a[parent], a[i]);
    i = parent;
    parent = (i - 1) / 2;
  }
}

int main()
{
  int a[] = {55, 21, 17, 63, 16, 35, 13, 38, 31, 41, 12};
  int n = sizeof(a)/sizeof(int);
  displayHeapTree(a, n);

  for(int i = n/2 - 1; i >= 0; --i)  {
    minHeapify(a, n, i);
  }
  displayHeapTree(a, n);
  cout << "min: " << getMin(a, &n) << endl << endl;
  displayHeapTree(a, n);

  insertKey(a, &n, 10);
  displayHeapTree(a, n);
}
