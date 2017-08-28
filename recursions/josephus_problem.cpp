#include <iostream>
using namespace std;

int josephus(int n, int k) {
//  if(n == 1) return 1;
//  return (josephus(n - 1, k) + k - 1) % n + 1;

  if(n == 0) return 0;
  return (josephus(n - 1, k) + k) % n;
}

int main()
{
//  cout << josephus(5, 3) << endl;
  for(int i = 0; i < 14; i++) {
    cout << i << " " << josephus(i, 2) << endl;
  }
}
