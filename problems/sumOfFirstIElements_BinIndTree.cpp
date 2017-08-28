#include <iostream>
#include <iomanip>
using namespace std;
/*
 *		index	        0	1	2	3	4	5	6	7	  8	9	  10	11
 *		arr[0..n-1]	  2	1	1	3	2	3	4	5	  6	7	  8	  9
 *		BITree[1..n]	2	3	1	7	2	5	4	21	6	13	8	  30
 *		index	        1	2	3	4	5	6	7	8	  9	10	11	12
 * 
 * Updating an array element => parent(i) = i + (i & -i)
 * 								          dummy(>12)
 *                 -----------------------------
 *  				       1000								      1100	
 *  				       (0,7)								    (8,11)	
 *  				       21(8)								    30(12)
 *      --------------------------      --------------
 *  	  0100			  0110			0111			1010		  1011
 *  	  (0,3)		  	(4,5)			(6,6)			(8,9)		  (10,10)
 *  	  7(4)		  	5(6)			4(7)			13(10)		8(11)
 * -------------    ----                ----
 * 0010		   0011	  0101							  1001		
 * (0,1)	   (2,2)	(4,4)							  (8,8)		
 * 3(2)		   1(3)	  2(5)							  6(9)		
 * ----
 * 0001													
 * (0,0)													
 * 2(1)													
 *
 * Time complexity: O(logn)
 */

void updateBiTree(int *biTree, int n, int i, int val)
{
  if(i > n) return;

  biTree[i] += val;

  updateBiTree(biTree, n, i + (i & (-i)), val);
}

void constructBiTree(int *biTree, int *a, int n)
{
  int start, end;

  for(int i = 1; i < n + 1; ++i) {
    updateBiTree(biTree, n, i, a[i - 1]);
  }
}

void display(int *a, int n)
{
  for(int i = 1; i < n; ++i) {
    cout << setw(3) << a[i];
  }
  cout << endl;
}
/*
 *	Sum of first I nums => parent(i) = i - (i & -i)
 *								              0(dummy)
 *              ----------------------------------------------
 *	bits		   0000			 0001				  0100				    	   1000			
 *	range		  (0,0)			(0,1)				  (0,3)					      (0,7)			
 *	index/val	 2(1)			 3(2)				  7(4)					      21(8)
 *	                     ---      -----------     ----------------------
 *					  	         0011			0101		0110		  1001		1010		  1100	
 *					  	        (2,2)			(4,4)		(4,5)		(8,8)		(8,9)		  (8,11)	
 *					  	         1(3)			2(5)		5(6)		 6(9)		13(10)		30(12)	
 *                                        ---             ----
 *					  						                111				      1011			
 *					  						                (6,6)				    (10,10)			
 *					  						                4(7)				    8(11)			
 * Time complexity: O(logn)
 */

int sumOfFirstINums(int *biTree, int i)
{
  if(i == 0)
    return biTree[i];

  return biTree[i] + sumOfFirstINums(biTree, i - (i & (-i)));
}

int main()
{
  int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  int biTree[n + 1] = {0};

  constructBiTree(biTree, arr, n);
  display(biTree, n + 1);
  for(int i = 0; i < n; i++) {
    cout << "Sum of first " << i + 1 << ": " << sumOfFirstINums(biTree, i + 1) << endl;
  }

  arr[3] += 6;
  updateBiTree(biTree, n, 3, 6);
  cout << "after updating the index 3 to +6" << endl;

  for(int i = 0; i < n; i++) {
    cout << "Sum of first " << i + 1 << ": " << sumOfFirstINums(biTree, i + 1) << endl;
  }

  return 0;
}
