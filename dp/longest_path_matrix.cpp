#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 3

int findLongestOverAll(int mat[][N], int path[][N], int i, int j)
{
  if(i < 0 || i >= N || j < 0 || j >= N) 
    return 0;

  if(path[i][j] != -1) 
    return path[i][j];
  
  if((mat[i][j] + 1) == mat[i][j+1])
    return path[i][j] = 1 + findLongestOverAll(mat, path, i, j+1);

  if((mat[i][j] + 1) == mat[i+1][j])
    return path[i][j] = 1 + findLongestOverAll(mat, path, i+1, j);
  
  if((mat[i][j] + 1) == mat[i][j-1])
    return path[i][j] = 1 + findLongestOverAll(mat, path, i, j-1);
  
  if((mat[i][j] + 1) == mat[i-1][j])
    return path[i][j] = 1 + findLongestOverAll(mat, path, i-1, j);

  return path[i][j] = 1;
}

int main()
{
  int  mat[N][N] = {{1, 2, 8},
                    {5, 3, 4},
                    {9, 6, 7}};
  int  path[N][N];
  int res;
  int maxPath = -1;

  memset(path, -1, sizeof(path));

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      res = findLongestOverAll(mat, path, i, j);
      if(res > maxPath)
        maxPath = res;
    }
  }

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      cout << path[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

