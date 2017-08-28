#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
#define M 0xFF  /* Mine */
#define X 0xFE  /* Blank */
#define B 0xFD  /* - */

vector<vector<int> > xy = {
  {-1, -1, -1, 0, 1, 1,  1,  0},
  {-1,  0,  1, 1, 1, 0, -1, -1}
};

void updateMatrix(vector<vector<int> > &temp, vector<vector<int> > &uMat, vector<vector<int> > &mat, int i, int j)
{
  if(mat[i][j] == M) {
    return;
  } else if(mat[i][j] > 0 && mat[i][j] < 9) {  
    temp[i][j] = mat[i][j];
    return;
  }

//  cout << i << " " << j << ": " << uMat[i][j] << " " << endl;
  int x, y;
  temp[i][j] = B;
  for(int k = 0; k < 8; k++)  {
    x = i + xy[0][k];
    y = j + xy[1][k];
    if(x < uMat.size() && y < uMat.size() && temp[x][y] != B) {
      updateMatrix(temp, uMat, mat, x, y);
    }
  }
}

void displayUserData(vector<vector<int> > &uMat, vector<vector<int> > &mat)
{
  vector<vector<int> > temp(uMat);

  for(int i = 0; i < uMat.size(); i++) {
    for(int j = 0; j < uMat[i].size(); j++) {
      if(uMat[i][j] == X) {
        updateMatrix(temp, uMat, mat, i, j);
      }
    }
  }

  cout << "   ";
  for(int j = 0; j < temp[0].size(); j++) {
    cout << setw(2) << j;
  }
  cout<< endl;
  cout << "  -----------------" << endl;
  for(int i = 0; i < temp.size(); i++) {
    cout << setw(2) << i << '|';
    for(int j = 0; j < temp[i].size(); j++) {
      if(temp[i][j] == M) {
        cout << setw(2) << 'M';
      } else if(temp[i][j] == B) {
        cout << setw(2) << '-';
      } else if(temp[i][j] == 0) {
        cout << setw(2) << 'o';
      } else {
        cout << setw(2) << temp[i][j];
      }
    }
    cout << endl;
  }
  cout << endl;
}

void display(vector<vector<int> > &mat)
{
  cout << "   ";
  for(int j = 0; j < mat[0].size(); j++) {
    cout << setw(2) << j;
  }
  cout<< endl;
  cout << "  -----------------" << endl;
  for(int i = 0; i < mat.size(); i++) {
    cout << setw(2) << i << '|';
    for(int j = 0; j < mat[i].size(); j++) {
      if(mat[i][j] == 0)  {
        cout << setw(2) << '-';
      } else if(mat[i][j] == M){
        cout << setw(2) << 'M';
      } else {
        cout << setw(2) << mat[i][j];
      }
    }
    cout << endl;
  }
  cout << endl;
}

void initializeNeighbors(vector<vector<int> > &mat)
{
  int x, y;
  for(int i = 0; i < mat.size(); i++) {
    for(int j = 0; j < mat[i].size(); j++) {
      if(mat[i][j] == M) {
        for(int k = 0; k < 8; k++)  {
          x = i + xy[0][k];
          y = j + xy[1][k];
          if(x < mat.size() && y < mat.size() && mat[x][y] != M)  {
            mat[x][y]++;
          }
        }
      }
    }
  }
}

void getUserInput(int &r, int &c, char &val)
{
  bool flag = false;

  do {
    flag = false;
    cout << "Enter [row,col,X/M] : "; cin >> r >> c >> val;
    cout << r << " " << c << " " << val << endl;
    if(r < 0 || r > 8 || c < 0 || c > 8 || (val != 'X' && val != 'M'))  {
      cout << "Wrong entry!";
      flag = true;
    }
  } while(flag);
}

bool checkForGameFinished(vector<vector<int> > &mat, vector<vector<int> > &uMat)
{
  for(int i = 0; i < mat.size(); i++) {
    for(int j = 0; j < mat[i].size(); j++) {
      if(mat[i][j] == M && uMat[i][j] != M)
        return false;
    }
  }
  return true;
}

void solveMinesweeper(vector<vector<int> > &mat)
{
  vector<vector<int> > userMat(mat.size(), vector<int>(mat[0].size(), 0));

  int r, c;
  char val;
  while(1) {
    system("clear");
//    display(mat);
    displayUserData(userMat, mat);
    if(checkForGameFinished(mat, userMat)) {
      cout << "You WON :-)" << endl;
      return;
    }
    getUserInput(r, c, val);
    if(val == 'X' && M == mat[r][c]) {
      display(mat);
      cout << "you hit a MINE, You lost!!!" << endl;
      return;
    } else if(val == 'M') {
      userMat[r][c] = M;
    } else if(val == 'X') {
      userMat[r][c] = X;
    } else {
      cout << "===> No handle" << endl;
    }
  }
}

void generateMatrix(vector<vector<int> > &m, int range, int numMines)
{
  srand(time(0));
  int i, j;
  for(int c = 0; c < numMines; ++c) {
    i = rand() % 8;
    j = rand() % 8;
    m[i][j] = M;
//    cout << i << " " << j << endl;
  }
//  display(m);
}

int main()
{
  bool play = 0;
  while(! play) {
    vector<vector<int> > mat(8, vector<int>(8, 0));
    generateMatrix(mat, 8, 10);
    initializeNeighbors(mat);
    solveMinesweeper(mat);
    cout << "wanna play again? ([0]yes [1]no): "; cin >> play;
  }
  return 0;
}
