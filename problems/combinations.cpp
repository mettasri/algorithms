#include <iostream>
#include <iomanip>
using namespace std;

void display(int *aux, int size)
{
  for(int i = 0; i < size; ++i) {
    cout << setw(2) << aux[i];
  }
  cout << endl;
}

void combinations(int *arr, int size, int *aux, int i)
{
  if(0 == size) {
    display(aux, i);
    return;
  }
  
  aux[i] = arr[size - 1];
  combinations(arr, size - 1, aux, i + 1);
  combinations(arr, size - 1, aux, i);
}

int main()
{
  int arr[] = {1, 2, 3, 4};
  int size = sizeof(arr)/sizeof(arr[0]);
  int aux[size];

  combinations(arr, sizeof(arr)/sizeof(arr[0]), aux, 0);
  return 0;
}
