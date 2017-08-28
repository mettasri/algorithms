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
  int i, j, k;

  for(k = 0; k < R/2; k++)
  {
    temp = image[k][k];
    for(i = k, j = k; i < R-1-k; i++)
      image[i][j] = image[i+1][j];
    
    for(; j < C-1-k; j++)
      image[i][j] = image[i][j+1];

    for(; i > k; i--)
      image[i][j] = image[i-1][j];

    for(; j > k+1; j--)
      image[i][j] = image[i][j-1];
    image[i][j] = temp;
  }
}

int main()
{
  int image[R][C] = 
   {{ 1,  2,  3,  4}, 
    {12, 13, 14,  5}, 
    {11, 16, 15,  6},
    {10,  9,  8,  7}
   };

  displayImage(image);
  rotate(image);
  displayImage(image);

  return 0;
}
