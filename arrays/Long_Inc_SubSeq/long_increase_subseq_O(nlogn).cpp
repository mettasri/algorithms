#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int getCeilPosition(int arr[], int T[], int l, int h, int k)
{
  int m;
  while((h - l) > 1)
  {
    m = (l + h)/2;
    if(k <= arr[T[m]])
      h = m;
    else
      l = m;
  }
  return h;
}

void print(int a[], int l)
{
  for(int i = 0; i < l; i++)
  {
    cout << setw(3) << a[i];
  }
  cout << endl;
}

int longIncreasingSubSequence(int arr[], int len) 
{
  int *T = new int [len];
  int *R = new int [len];
  int L;
  int pos;

  memset(R, 0xFF, sizeof(int)*len);
  memset(T,  0, sizeof(int)*len);
  L = 1;
  for(int i = 1; i < len; i++)
  {
    if(arr[i] < arr[T[0]])
      T[0] = i;
    else if(arr[i] > arr[T[L - 1]])
    {
      R[i] = T[L - 1];
      T[L++] = i;
    }
    else
    {
      pos = getCeilPosition(arr, T, 0, L - 1, arr[i]);
      T[pos] = i;
      R[i] = T[pos - 1];
    }
//    print(T, len);
//    print(R, len);
//    cout << endl;
  }

  int *Res = new int [L];
  int j;
  for(int i = T[L - 1], j = 0; i >= 0; i = R[i], j++)
    Res[L - j - 1] = arr[i];
  
  print(Res, L);

  delete []T;
  delete []R;
  delete []Res;

  return L;
}

int main()
{
  int arr[] = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
//  int arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
  int len = sizeof(arr)/sizeof(arr[0]);
  
  cout << "LIS: " << longIncreasingSubSequence(arr, len) << endl;

  return 0;
}

