// A Dynamic Programming based C++ program to count paths with
// exactly 'k' coins
#include <bits/stdc++.h>
#define R 3
#define C 3
#define MAX_K 1000
using namespace std;
 
int dp[R][C][MAX_K];
 
int pathCountDPRecDP(int mat[][C], int m, int n, int k)
{
    // Base cases
    if (m < 0 || n < 0) return 0;
    if (m==0 && n==0) return (k == mat[m][n]);
 
    // If this subproblem is already solved
    if (dp[m][n][k] != -1) return dp[m][n][k];
 
    // (m, n) can be reached either through (m-1, n) or
    // through (m, n-1)
    dp[m][n][k] = pathCountDPRecDP(mat, m-1, n, k-mat[m][n]) +
                  pathCountDPRecDP(mat, m, n-1, k-mat[m][n]);
    cout << setw(2) << m << setw(2) << n << setw(2) << k << " =" << setw(2) << dp[m][n][k] << setw(2) << "(" << m-1 << " " << setw(2) << n << " " << setw(2) << k-mat[m][n] << "  + " << setw(2) << m  << " " <<  setw(2) << n-1 << " " << setw(2) << k-mat[m][n] << ")" << endl;
    return dp[m][n][k];
}
 
// This function mainly initializes dp[][][] and calls
// pathCountDPRecDP()
int pathCountDP(int mat[][C], int k)
{
  memset(dp, -1, sizeof dp);

  dp[R-1][C-1][k-1] = pathCountDPRecDP(mat, R-1, C-1, k);

  cout << endl;
  for(int c = 0; c < k; c++)
    cout << setw(2) << c << " ";
  cout << endl;

  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
    {
      for(int c = 0; c < k; c++)
      {
        cout << setw(2) << dp[i][j][c] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return (dp[R-1][C-1][k-1]);

}
 
// Driver Program to test above functions
int main()
{
    int k = 12;
    int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << pathCountDP(mat, k);
    return 0;
}
