#include <iostream>
using namespace std;

/*
int numberOfPaths(int m, int n)
{
  if(m == 1 || n == 1)
    return 1;

  return (numberOfPaths(m-1, n) + numberOfPaths(m, n-1));
}
*/

int numberOfPaths(int m, int n)
{
  int countPath[m][n];

  for(int i = 0; i < m; i++)
    countPath[i][0] = 1;
  for(int i = 0; i < n; i++)
    countPath[0][i] = 1;

  for(int i = 1; i < m; i++)
  {
    for(int j = 1; j < n; j++)
      countPath[i][j] = countPath[i-1][j] + countPath[i][j-1]; // + countPath[i-1][j-1];
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cout << countPath[i][j] << " ";
    }
    cout << endl;
  }
  return countPath[m-1][n-1];
}

int main()
{
  cout << numberOfPaths(3, 3);
  return 0;
}
