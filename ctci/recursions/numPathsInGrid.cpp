#include <iostream>
using namespace std;

int numPathsInGrid(int r, int c)
{
  if(1 == r || 1 == c) return 1;

  return numPathsInGrid(r - 1, c) + numPathsInGrid(r, c - 1);
}

int main()
{
  cout << numPathsInGrid(3, 3) << endl;
}
