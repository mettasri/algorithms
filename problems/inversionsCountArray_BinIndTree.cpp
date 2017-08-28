#include <iostream>
using namespace std;

/*
 * getSum => parent(i) = i - (i & -i)
 * Time Complexity => O(nlog(maxEle))
 *
 *	  				0
 *	-------------------------
 *  1			2				4			    8
 *				-			-----		-----------
 *			  3			5		6		9   10   12
 *									-	      --   --
 *								  7		    11   13
 * 
 *
 * updateBiTree => parent(i) = i + (i & -i)
 * Time Complexity => O(nlog(maxEle))
 *
 *                          >16
 *                -------------------------
 *                8                      16
 *         ---------------      --------------------
 *         4      6      7      12       14       15
 *       ------   -            --------  --
 *       2    3   5            10    11  13
 *       -                     --
 *       1                      9
 * Space Complexity => O(n)
 *
 * Eg:
 *  Index : 0 1 2 3 4
 *  array : 4 2 5 3 1
 *  Bitree: 3 1 2 1 0
 *  Index : 1 2 3 4 5 (Note: index 0 ignored)
 *          1 1   1
 *              3 4
 *                  5
 *            2   2
 *                3
 */

int getInversions(int *biTree, int n, int i)
{
  int count = 0;
//  cout << i << ": ";

  while(i > 0) {
    count += biTree[i];
    i -= (i & -i);
  }

//  cout << count << endl;
  return count;
}

int updateBiTree(int *biTree, int n, int i)
{
  while(i <= n) {
    biTree[i]++;
    i += (i & -i);
  }
}

int numInversionsBinIndTree(int *a, int n)
{
  int count = 0;
  int max = a[0];

  for(int i = 1; i < n; i++) {
    if(max < a[i])
      max = a[i];
  }
  
  int *biTree = new int[max + 1];
  // Reset Binary Index Tree
  for(int i = 0; i < (max + 1); i++)
    biTree[i] = 0;

  for(int i = n - 1; i >= 0; i--) {
    count += getInversions(biTree, max + 1, a[i] - 1);
    updateBiTree(biTree, max + 1, a[i]);
  }

//  for(int i = 1; i < (max + 1); i++)
//    cout << biTree[i] << " ";
//  cout << endl;
  
  return count;
}

int main()
{
  int arr0[] = {4, 2, 5, 3, 1};
  int n0 = sizeof(arr0)/sizeof(arr0[0]);
  cout << "num inversions: " << numInversionsBinIndTree(arr0, n0) << endl;

  int arr1[] = {5, 4, 2, 3, 1};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  cout << "num inversions: " << numInversionsBinIndTree(arr1, n1) << endl;

  int arr2[] = {6, 9, 1, 14, 8, 12, 3, 2};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  cout << "num inversions: " << numInversionsBinIndTree(arr2, n2) << endl;

  return 0;
}
