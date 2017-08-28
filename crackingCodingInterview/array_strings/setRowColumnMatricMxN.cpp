#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int printMatrix(vector<vector<int> > &m)
{
  for(int i = 0; i < m.size(); i++) {
    for(int j = 0; j < m[i].size(); j++) {
      cout << setw(3) << m[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void setRowColumnOfMatrixMxN(vector<vector<int> > &m)
{
  vector<int> r(m.size(), 1);
  vector<int> c(m[0].size(), 1);

  for(int i = 0; i < m.size(); i++) {
    for(int j = 0; j < m[i].size(); j++) {
      if(m[i][j] == 0) {
        r[i] = 0;
        c[j] = 0;
      }
    }
  }

  for(int i = 0; i < m.size(); i++) {
    for(int j = 0; j < m[i].size(); j++) {
      if(r[i] == 0 || c[j] == 0){
        m[i][j] = 0;
      }
    }
  }
}

int main()
{
  vector<vector<int> > matrix = 
  {
    {1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1}
  };

  printMatrix(matrix);
  setRowColumnOfMatrixMxN(matrix);
  printMatrix(matrix);
}
