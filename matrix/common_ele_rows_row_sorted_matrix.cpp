#include <iostream>
#include <iomanip>
using namespace std;

#define R 4
#define C 5

void diplay(int a[])
{
  for(int r = 0; r < R; r++)
    cout << setw(3) << a[r];
//  cout << endl;
}

int findMinRow(int mat[][C], int col[])
{
  int min_row = 0;
  for(int r = 0; r < R; r++)
  {
    if(mat[r][col[r]] < mat[min_row][col[min_row]])
    {
      min_row = r;
    }
  }
  return min_row;
}

int findCommon(int mat[][C])
{
  int col[R];
  int count;
  int min_row;

  for(int r = 0; r < R; r++)
    col[r] = C - 1;
  diplay(col);

  while(col[min_row] >= 0)
  {
    count = 0;
    min_row = findMinRow(mat, col);
    cout << "   min_row: " << min_row << endl;
    for(int r = 0; r < R; r++)
    {
      if(mat[r][col[r]] > mat[min_row][col[min_row]])
      {
        if(col[r] == 0)
          return -1;
        col[r] -= 1;
      }
      else
        count++;
    }
    diplay(col);
    if(count == R)
    {
      return mat[min_row][col[min_row]];
    }
  }
  return (-1);
}

int main()
{
//  int mat[R][C] = { {1, 2, 3, 4, 5},
//                    {2, 4, 6, 8, 10},
//                    {4, 5, 7, 9, 11},
//                    {1, 4, 5, 7, 9},
//                  };
  int mat[R][C] = { {2, 3, 4, 5, 6},
                    {1, 4, 6, 8, 10},
                    {2, 5, 7, 9, 11},
                    {2, 4, 5, 7, 9},
                  };
  int result = findCommon(mat);
  if (result == -1)
    cout << " No common element" << endl;
  else
    cout << " Common element is " << result << endl;

  return 0;
}
