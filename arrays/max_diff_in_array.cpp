#include <iostream>
using namespace std;

int maxDiffWithMaxInHigherIndex(int arr[], int size)
{
  int max_index = size - 1;
  int maxDiff = -1;

  for(int i = size - 2; i >= 0; i--)
  {
    if(arr[i] < arr[max_index])
      maxDiff = arr[max_index] - arr[i];
    else
      max_index = i;
  }

  return maxDiff;
}

int main()
{
  int arr[] = {10, 21};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << maxDiffWithMaxInHigherIndex(arr, size) << endl;
}
