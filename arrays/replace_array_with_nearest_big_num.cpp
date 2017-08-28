#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void replaceNearestBigNum(vector<int> &v)
{
  stack<int> mystack;

  mystack.push(0);

  for(int i = 1; i < v.size(); ++i)
  {
    while(! mystack.empty() && v[i] > v[mystack.top()])
    {
      v[mystack.top()] = v[i];
      mystack.pop();
    }
    mystack.push(i);
  }
}

int main()
{
//  int arr[] = {40, 50, 11, 32, 55, 68, 75};
  int arr[] = {7, 5, 6, 3, 4, 1, 2, 9, 11};
  vector <int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;

  replaceNearestBigNum(v);

  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
