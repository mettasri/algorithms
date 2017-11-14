#include <iostream>
#include <vector>
using namespace std;

/*
 * Top Down(momorization approach): it looks into a lookup table 
 * before computing solutions
 *  
 *                           fib(5)
 *                       /             \
 *                 fib(4)                fib(3)
 *               /      \                /     \
 *           fib(3)      fib(2)         fib(2)    fib(1)
 *          /     \        /    \       /    \
 *    fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
 *    /    \
 *  fib(1) fib(0)
 *
 */
int fib(int n, vector<int>& lookUp)
{
  if(n < 2) {
    lookUp[n] = n;
    return lookUp[n];
  }
  if(-1 == lookUp[n]) {
    lookUp[n] = fib(n-1, lookUp) + fib(n-2, lookUp);
  }
  
  return lookUp[n];
}

int main()
{
  int n = 40;
  vector<int> lookUp(n+1, -1);
  
  cout << fib(n, lookUp) << endl;

  for(int i = 0; i <= n; ++i)
    if(-1 != lookUp[i])
      cout << lookUp[i] << " ";

  return 0;
}
