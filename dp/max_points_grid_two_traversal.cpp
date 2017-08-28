#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define R 5
#define C 4

int max(int a, int b)
{
  return ((a > b) ? a : b);
}

int getMaxCollection(int a[][C], int dp[][C][C], int i, int j1, int j2, int ind)
{
  /* out of Grid */
  if((i < 0) || (i >= R) || (j1 < 0) || (j1 >= C) || (j2 < 0) || (j2 >= C))
  {
    return INT_MIN;
  }

  cout << setw(2*ind) << i << "," << j1 << "," << j2 << endl;

  if(dp[i][j1][j2] != -1)
  {
    cout << setw(2*ind) << i << "," << j1 << "," << j2 << "[" << dp[i][j1][j2] << "]" << endl;
    return dp[i][j1][j2];
  }

  /* reached destination */
  if(i == R-1 && j1 == 0 && j2 == C-1)
  {
    cout << setw(2*ind) << i << "," << j1 << "," << j2 << "[" << a[i][j1] + a[i][j2] << "]" << endl;
    return dp[i][j1][j2] = a[i][j1] + a[i][j2];
  }

  /* not at their destination */
  if(i == (R - 1))
  {
    cout << setw(2*ind) << i << "," << j1 << "," << j2 << "[" << INT_MIN << "]" << endl;
    return INT_MIN;
  }

  int result = INT_MIN;
  int temp = ((j1 == j2) ? a[i][j1] : a[i][j1] + a[i][j2]);

  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1,   j2,   ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1,   j2-1, ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1,   j2+1, ind + 1));

  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1-1, j2,   ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1-1, j2-1, ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1-1, j2+1, ind + 1));

  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1+1, j2,   ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1+1, j2-1, ind + 1));
  result = max(result, temp + getMaxCollection(a, dp, i + 1, j1+1, j2+1, ind + 1));

  cout << setw(2*ind) << i << "," << j1 << "," << j2 << "[" << result << "]" << endl;

  return (dp[i][j1][j2] = result);
}

int main()
{
  int arr[R][C] = {
        /*0  1   2   3*/
    /*0*/{3, 6,  8,  2},
    /*1*/{5, 2,  4,  3},
    /*2*/{1, 1, 20, 10},
    /*3*/{1, 1, 20, 10},
    /*4*/{1, 2, 30, 10}
  };
  int dp[R][C][C];
  memset(dp, -1, sizeof(dp));
  cout << "Maximum collection is " << getMaxCollection(arr, dp, 0, 0, C-1, 1) << endl;
  return 0;
}
