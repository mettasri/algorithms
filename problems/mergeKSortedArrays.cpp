#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void mergeArraysFromEnd(int *a, int l, int *a1, int l1, int *a2, int l2)
{
//  cout << l << " " << l1 << " " << l2 << endl;
  if(0 == l1)  {
    while(l2 > 0) {
      a[--l] = a2[--l2];
    }
    return;
  }
  if(0 == l2)  {
    while(l1 > 0) {
      a[--l] = a1[--l1];
    }
    return;
  }
  if(a1[l1 - 1] < a2[l2 - 1]) {
    a[--l] = a2[--l2];
    mergeArraysFromEnd(a, l, a1, l1, a2, l2);
    return;
  } else  {
    a[--l] = a1[--l1];
    mergeArraysFromEnd(a, l, a1, l1, a2, l2);
    return;
  }
}

void display(int *a, int l)
{
  for(int i = 0; i < l; i++) {
    cout << setw(3) << a[i];
  }
  cout << endl;
}

class matxy
{
  public:
    int x;
    int y;
    int val;
};

void swap(matxy &x, matxy &y)
{
  matxy temp = x;
  x = y;
  y = temp;
}

void minHeapify(vector<matxy> &heapData, int i)
{
  int lc = 2*i + 1;
  int rc = 2*i + 2;
  int small = i;

  if(lc < heapData.size() && heapData[lc].val < heapData[small].val)
    small = lc;

  if(rc < heapData.size() && heapData[rc].val < heapData[small].val)
    small = rc;

//  cout << small << "  " << i << endl;
  if(small != i)  {
    swap(heapData[i], heapData[small]);
    minHeapify(heapData, small);
  }
}

matxy getMin(vector<matxy> &heapData)
{
  matxy xy = heapData[0];
  if(heapData.size() == 1)  {
    heapData.resize(0);
    return xy;
  }

  int size = heapData.size();
  heapData[0] = heapData[size - 1];
  heapData.resize(size - 1);
//  cout << heapData.size() << endl;
  minHeapify(heapData, 0); 

  return xy;
}

void display(vector<matxy> &heapData)
{
  for(int i = 0; i < heapData.size(); i++) {
    cout << setw(3) << heapData[i].val;
  }
  cout << endl;
}

void mergeKArrays(vector<vector<int> > &mat, vector<int> &vec)
{
  vector<matxy> heapData(mat.size());
  for(int i = 0; i < mat.size(); i++) {
    heapData[i].x = i;
    heapData[i].y = 0;
    heapData[i].val = mat[i][0];
  }

  for(int i = heapData.size()/2 - 1; i >= 0; --i)  {
    minHeapify(heapData, i);
  }
  display(heapData);

  matxy xy;
  while(heapData.size() > 0) {
    xy = getMin(heapData);
    cout << "pop: " << xy.val << endl;
    vec.push_back(xy.val);
    if((xy.y + 1) < mat[xy.x].size())  {
      xy.y++;
      xy.val = mat[xy.x][xy.y];
      cout << "pushed: " << xy.val << endl;
      heapData.push_back(xy);

      display(heapData);
      int size = heapData.size();
      int i = size - 1;
      int parent = (i - 1)/2;
      while(i != 0 && heapData[i].val < heapData[parent].val) {
        swap(heapData[i], heapData[parent]);
        i = parent;
        parent = (i - 1)/2;
      }
      display(heapData);
    }
  }
}

int main()
{
  int arr1[] = {10, 30, 35, 40, 60};
  int arr2[] = { 6, 20, 25, 34};
  int arr3[] = { 1, 11, 21, 24, 41, 44};
  int arr4[] = { 5, 19, 26, 27};
  int arr5[] = { 3, 8, 15, 22, 39, 54};
  
//  int size1 = sizeof(arr1)/sizeof(int);
//  int size2 = sizeof(arr2)/sizeof(int);
//  int size3 = sizeof(arr3)/sizeof(int);
//  int size = size1 + size2 + size3;

  vector<vector<int> > mat(5);
  mat[0].assign(arr1, arr1+sizeof(arr1)/sizeof(int));
  mat[1].assign(arr2, arr2+sizeof(arr2)/sizeof(int));
  mat[2].assign(arr3, arr3+sizeof(arr3)/sizeof(int));
  mat[3].assign(arr4, arr4+sizeof(arr4)/sizeof(int));
  mat[4].assign(arr5, arr5+sizeof(arr5)/sizeof(int));
//  for(int i = 0; i < mat[2].size(); i++)
//    cout << mat[2][i] << endl;

  vector<int> vec;
  mergeKArrays(mat, vec);
  cout << "Sorted ele: " << endl;
  for(int i = 0; i < vec.size(); i++)
    cout << setw(3) << vec[i];
  cout << endl;


//  int arr[size];
//  int *mat[] = {arr1, arr2, arr3};
//  for(int i = 0; i < size1; i++)
//    cout << mat[1][i] << endl;

//  mergeArraysFromEnd(arr, size1+size2, arr1, size1, arr2, size2);
//  mergeArraysFromEnd(arr, size, arr, size1+size2, arr3, size3);
//  display(arr, size);
}
