#include <iostream>
#include <vector>
using namespace std;

int numPathsInGrid(vector<vector<bool> > &mat, int r, int c)
{
  if(0 == mat[r - 1][c - 1]) return 0;
  if(1 == r && 1 == c) return 1;

  int lc = (r > 1) ? numPathsInGrid(mat, r - 1, c) : 0;
  int rc = (c > 1) ? numPathsInGrid(mat, r, c - 1) : 0;

  return (lc + rc);
}

int numPathsInGridDP(vector<vector<bool> > &mat)
{
  if(! mat[0][0]) return 0;

  int m = mat.size();
  int n = mat[0].size();

  vector<vector<int> > arr(m, vector<int>(n, 0));
  arr[0][0] = 1;
  for(int i = 1; i < m; i++) {
    if(mat[0][i])
      arr[0][i] = arr[0][i - 1];
    if(mat[i][0])
      arr[i][0] = arr[i - 1][0];
  }

  for(int i = 1; i < m; i++) {
    for(int j = 1; j < n; j++) {
      if(mat[i][j])
        arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

//  for(int i = 0; i < m; i++) {
//    for(int j = 0; j < n; j++)
//      cout << arr[i][j] << " ";
//    cout << endl;
//  }
  return arr[m - 1][n - 1];
}

int main()
{
  vector<vector<bool> > mat{
      {1, 0, 1},
      {1, 1, 1},
      {1, 0, 1}
      };
  cout << numPathsInGrid(mat, 3, 3) << endl;
  cout << numPathsInGridDP(mat) << endl;
}
