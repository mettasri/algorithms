#include <iostream>
using namespace std;
 
// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(int m, int n)
{
   // If either given row number is first or given column number is first
   cout << m << " " << n<< endl;
   if (m == 1 || n == 1)
        return 1;
 
   // If diagonal movements are allowed then the last addition
   // is required.
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1) 
            + numberOfPaths(m-1,n-1);
}

int findpath(int a[][3],int n,int i,int j)
{
  int l=0,r=0,c=0;
  cout << i << " " << j << endl;
  if(i==n-1 && j==n-1)          //reached destination
      return 1;
  if(j+1<n && a[i][j+1]!=0)    // is Right Possible
      l=findpath(a, n, i, j+1);
  if(i+1<n && a[i+1][j]!=0)    //  is Down Possible
      r=findpath(a,n,i+1,j);
  if(i+1<n && j+1<n && a[i+1][j+1]!=0)    //  is diagonal
      c=findpath(a,n,i+1,j+1);
  return l+r+c;
}
 
int main()
{
//    cout << numberOfPaths(3, 3) << endl;
    int a[3][3] = { {1, 1, 1},
                    {1, 1, 1},
                    {1, 1, 1}
                };
    cout << findpath(a, 3, 0, 0) << endl;
    return 0;
}
