/*
 * Given two positive integers n and k, print all increasing sequences of length k such that the elements in every sequence are from first n natural numbers.
 * Examples:
 * Input: k = 2, n = 3
 * Output: 1 2
 *         1 3
 *         2 3 
 * 
 * Input: k = 5, n = 5
 * Output: 1 2 3 4 5
 * 
 * Input: k = 3, n = 5
 * Output: 1 2 3
 *         1 2 4
 *         1 2 5
 *         1 3 4
 *         1 3 5
 *         1 4 5
 *         2 3 4
 *         2 3 5
 *         2 4 5
 *         3 4 5
 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void display(vector<int>& v)
{
  for(int i = 0; i < v.size(); i++)
    cout << setw(3) << v[i];
  cout << endl;
}

void printSeqVector(int start, int end, int k, vector<int>& v)
{
  if(v.size() == k) {
    display(v);
    return;
  }

  for(int i = start; i <= end; i++) {
    v.push_back(i);
    printSeqVector(i + 1, end, k, v);
    v.pop_back();
  }
}

void displayArray(int *arr, int k)
{
  for(int i = 0; i < k; i++)
    cout << setw(3) << arr[i];
  cout << endl;
}

void printSeqArray(int start, int end, int k, int ind, int *arr)
{
  if(ind == k) {
    displayArray(arr, k);
    return;
  }

  for(int i = start; i <= end; i++) {
    arr[ind] = i;
    printSeqArray(i + 1, end, k, ind + 1, arr);
  }
}

int main ()
{
  int k = 3, n = 5;
//  vector<int> v;
//  printSeqVector(1, n, k, v);

  int arr[10];
  printSeqArray(1, n, k, 0, arr);

  return 0;
}
