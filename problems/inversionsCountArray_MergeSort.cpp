#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &v)
{
  for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

int merge(vector<int> &v, vector<int> &l, vector<int> &r)
{
  int i = 0, j = 0, count = 0;

  while(i < l.size() || j < r.size()) {
    if(j >= r.size()) {
      v[i + j] = l[i]; i++;
    } else if(i >= l.size()) {
      v[i + j] = r[j]; j++;
    } else if(l[i] < r[j]) {
      v[i + j] = l[i]; i++;
    } else {
      v[i + j] = r[j]; j++;
      count += l.size() - i;
    }
  }
  return count;
}

int numInversions(vector<int> &v)
{
  if(v.size() < 2) {
    return 0;
  }

  int numInver = 0;
  int mid = v.size()/2;
  vector<int> left(v.begin(), v.begin() + mid);
  vector<int> right(v.begin() + mid, v.end());

  return numInversions(left) + numInversions(right) + merge(v, left, right);
}

int main()
{
  int arr1[] = {6, 9, 1, 14, 8, 12, 3, 2};

  vector<int> vec1(arr1, arr1 + (sizeof(arr1)/sizeof(arr1[0])));
  cout << "num inversions: " << numInversions(vec1) << endl;
  display(vec1); cout << endl;

  int arr2[] = {5, 4, 2, 3, 1};
  vector<int> vec2(arr2, arr2 + (sizeof(arr2)/sizeof(arr2[0])));
  cout << "num inversions: " << numInversions(vec2) << endl;
  display(vec2); cout << endl;

  return 0;
}
