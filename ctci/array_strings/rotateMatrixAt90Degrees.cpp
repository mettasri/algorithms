#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int> > &matrix)
{
  for(int i = 0; i < matrix.size(); i++)  {
    for(int j = 0; j < matrix[i].size(); j++)  {
      cout << setw(3) << matrix[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void rotateMatrixBy90Degrees(vector<vector<int> > &m, int N)
{
  int temp;

  for(int i = 0; i < N/2; i++) {
    for(int j = i; j < N - i - 1; j++) {
      temp = m[i][j];
      m[i][j] = m[N - j - 1][i];
      m[N - j - 1][i] = m[N - i - 1][N - j - 1];
      m[N - i - 1][N - j - 1] = m[j][N - i - 1];
      m[j][N - i - 1] = temp;
//      00 = 30 | 01 = 20 | 02 = 10
//      30 = 33 | 20 = 32 | 10 = 31
//      33 = 03 | 32 = 13 | 31 = 23
//      03 = 00 | 13 = 01 | 23 = 02
//
//      11 = 21
//      21 = 22
//      22 = 12
//      12 = 11
    }
  }
}

int main()
{
  vector<vector<int> > matrix = 
   {{00, 01, 02, 03},
    {10, 11, 12, 13},
    {20, 21, 22, 23},
    {30, 31, 32, 33}};

//   {{30, 20, 10, 00},
//    {31, 21, 11, 01},
//    {32, 22, 12, 02},
//    {33, 23, 13, 03}};
  printMatrix(matrix);
  rotateMatrixBy90Degrees(matrix, 4);
  printMatrix(matrix);

  vector<vector<int> > matrix1 = 
   {{00, 01, 02, 03, 04},
    {10, 11, 12, 13, 14},
    {20, 21, 22, 23, 24},
    {30, 31, 32, 33, 34},
    {40, 41, 42, 43, 44}};

  printMatrix(matrix1);
  rotateMatrixBy90Degrees(matrix1, 5);
  printMatrix(matrix1);
}
