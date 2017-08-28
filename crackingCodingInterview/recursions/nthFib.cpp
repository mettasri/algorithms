#include <iostream>
#include <iomanip>
using namespace std;

int nthFib(int n)
{
  if(n < 2) return n;

  return nthFib(n - 1) + nthFib(n - 2);
}

int main()
{
  for(int i = 1; i < 10; i++) {
    cout << setw(3) << nthFib(i);
  }
}
