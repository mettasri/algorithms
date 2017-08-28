#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;

void displaySet(set<int> &mySet)
{
  set<int>::iterator it;
  for(it = mySet.begin(); it != mySet.end(); it++)
    cout << setw(3) << *it;
  cout << endl;
}

int findCommon(vector<vector<int>> &mat)
{
  set<int> set1;
  set<int> set2;
  set<int>::iterator it;

  for(int c = 0; c < mat[0].size(); c++)
  {
    set1.insert(mat[0][c]);
  }
  displaySet(set1);

  for(int r = 1; r < mat.size(); r++)
  {
    for(int c = 0; c < mat[r].size(); c++)
    {
      it = set1.find(mat[r][c]);
      if(it != set1.end())
      {
        set2.insert(mat[r][c]);
      }
    }
    displaySet(set2);
    set1 = set2;
    set2.clear();
  }
  it = set1.begin();
  return it != set1.end() ? (*it) : (-1);
}

int main()
{
// vector<vector<int>> mat = {{1, 2, 3, 4, 5},
//                            {2, 4, 6, 8, 10},
//                            {4, 5, 7, 9, 11},
//                            {1, 4, 5, 7, 9},
//                           };
  vector<vector<int>> mat = {{6, 3, 5, 4, 2},
                             {8, 10, 2, 6, 4, 15},
                             {5, 1, 2, 11, 8},
                             {4, 2, 5, 9, 7},
                            };
  int result = findCommon(mat);
  if (result == -1)
    cout << " No common element" << endl;
  else
    cout << " Common element is " << result << endl;

  return 0;
}
