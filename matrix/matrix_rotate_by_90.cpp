#include <iostream>
#include <iomanip>
using namespace std;

#define R 4
#define C 4

void displayImage(int image[][C])
{
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
      cout << setw(3) << image[i][j];
    cout << endl;
  }
  cout << endl;
}

void rotate(int image[][C])
{
  int temp;

  for(int i = 0; i < R/2; i++)
  {
    for(int j = i; j < C-1-i; j++)
    {
      temp = image[i][j];
      image[i][j] = image[C-1-j][i];
      image[C-1-j][i] = image[C-1-i][C-1-j];
      image[C-1-i][C-1-j] = image[j][C-1-i];
      image[j][C-1-i] = temp;
//      displayImage(image);
    }
  }
}

int main()
{
  int image[R][C] = 
   {{ 1,  2,  3,  4}, 
    { 5,  6,  7,  8}, 
    { 9, 10, 11, 12},
    {13, 14, 15, 16}
   };

  displayImage(image);
  rotate(image);
  displayImage(image);

  return 0;
}
