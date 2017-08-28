#include <iostream>
#include <iomanip>
using namespace std;

//#define R 3
//#define C 6

//#define R 6
//#define C 3

#define R 4
#define C 4

void displayImage(int image[][C])
{
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
      cout << setw(3) << i << "," << j;
//      cout << setw(3) << image[i][j];
    cout << endl;
  }
  cout << endl;
}

void rotate(int image[][C])
{
  int temp;
  int r_s = 0, r_e = R, c_s = 0, c_e = C, i;

  while(r_s < r_e && c_s < c_e)
  {
//    cout << "r_s: " << r_s << " c_s: " << c_s << " c_e: " << c_e << endl;
    for(i = c_s; i < c_e; i++)
      cout << setw(3) << r_s << "," << i;
    cout << endl;
    r_s++;

//    cout << "c_e: " << c_e << " r_s: " << r_s << " r_e: " << r_e << endl;
    for(i = r_s; i < r_e; i++)
      cout << setw(3) << i << "," << c_e - 1;
    cout << endl;
    c_e--;

    if(r_s < r_e)
    {
//      cout << "r_e: " << r_e << " c_s: " << c_s << " c_e: " << c_e << endl;
      for(i = c_e - 1; i >= c_s; i--)
        cout << setw(3) << r_e - 1 << "," << i;
      cout << endl;
      r_e--;
    }

    if(c_s < c_e)
    {
//      cout << "r_e: " << r_e << " r_s: " << r_s << " c_s: " << c_s << endl;
      for(i = r_e - 1; i >= r_s; i--)
        cout << setw(3) << i << "," << c_s;
      cout << endl;
      c_s++;
    }
    cout << endl;
    cout << endl;
  }
}

int main()
{
//  int image[3][6] =
//   {{1,  2,  3,  4,  5,  6},
//    {7,  8,  9,  10, 11, 12},
//    {13, 14, 15, 16, 17, 18}
//   };
//
//  displayImage(image);
//  rotate(image);

//  int image1[6][3] =
//   {{ 1,  2,  3},
//    { 4,  5,  6},
//    { 7,  8,  9},
//    {10, 11, 12},
//    {13, 14, 15},
//    {16, 17, 18}
//   };
//
//  displayImage(image1);
//  rotate(image1);

  int image2[4][4] = 
   {{ 1,  2,  3,  4}, 
    { 5,  6,  7,  8}, 
    { 9, 10, 11, 12},
    {13, 14, 15, 16}
   };
  displayImage(image2);
  rotate(image2);

  return 0;
}
