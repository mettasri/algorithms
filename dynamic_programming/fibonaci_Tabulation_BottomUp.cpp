#include <iostream>
#include <vector>
using namespace std;

/*
 * Bottom Up(Tabulation): Builds table in bottom up fashion and returns
 * the last entry from table
 */

int fib(int n)
{
  vector<int> f(n+1, 0);

  f[0] = 0, f[1] = 1;
  for(int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  return f[n];
}

int main()
{
  cout << fib(40) << endl;

  return 0;
}
