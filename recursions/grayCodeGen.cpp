#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

void printResult(list<int> &code) {
  for(auto i : code)
    cout << i;
  cout << endl;
}

void genGrayCodeRecursive(list<int> &code, int n, bool isRight)  {
  if(n == 0) {
    printResult(code);
    return;
  }

  (isRight == true) ? code.push_back(1) : code.push_back(0);
  genGrayCodeRecursive(code, n - 1, false);
  code.pop_back();

  (isRight == true) ? code.push_back(0) : code.push_back(1);
  genGrayCodeRecursive(code, n - 1, true);
  code.pop_back();
}

void genGrayCode(int n) {
  int size = pow(2, n);
  int count = 0;
  vector<int> vec(size, 0);

  vec[count++] = 0;
  vec[count++] = 1;
  int k;
  for(int i = 1; i < n; i++)  {
    k = count - 1;
    while(k >= 0) {
      vec[count++] = vec[k--] | 1 << i;
    }
  }
  for(auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{
  int n = 4;
  list<int> code;

//  genGrayCodeRecursive(code, n, false);
  genGrayCode(n);
}
