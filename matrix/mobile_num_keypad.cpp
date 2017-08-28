#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int possibleNumFromLengthUtil(vector<vector<int>> &keypad, int r, int c, int n, int ind)
{
  if(r < 0 || r >=4 || c < 0 || c >= 3)
    return 0;

  if(keypad[r][c] == '*' || keypad[r][c] == '#')
    return 0;

//  cout << setw(2*ind) << keypad[r][c] << endl;
  if(n == 1)
    return 1;

  int count = 0;
  int x[] = {0,  0, 0, -1, 1};
  int y[] = {0, -1, 1,  0, 0};
  for(int i = 0; i < 5; i++)
  {
    count += possibleNumFromLengthUtil(keypad, r + x[i], c + y[i], n - 1, ind + 1);
  }

  return count;
}

int possibleNumFromLength(vector<vector<int>> &keypad, int n)
{
  int count = 0;
  for(int r = 0; r < keypad.size(); r++)
  {
    for(int c = 0; c < keypad[r].size(); c++)
    {
      count += possibleNumFromLengthUtil(keypad, r, c, n, 1);
    }
  }

  return count;
}

int main()
{
  vector<vector<int>> keypad = {
                    {1,   2,  3},
                    {4,   5,  6},
                    {7,   8,  9},
                    {'*', 0, '#' }
                   };

//  cout << "Count: " << possibleNumFromLength(keypad, 1) << endl;
//  cout << "Count: " << possibleNumFromLength(keypad, 2) << endl;
  cout << "Count: " << possibleNumFromLength(keypad, 3) << endl;
  cout << "Count: " << possibleNumFromLength(keypad, 4) << endl;
}
