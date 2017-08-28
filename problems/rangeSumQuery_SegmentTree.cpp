#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
/*
 *           0	1	2	3	4	5
 * arr:      1	3	5	7	9	11
 *
 *           0  1 2  3 4 5  6  7 8	9	10	11	12	13	14
 * segtree:  36 9 27 4 5 16 11 1 3			  7	  9		
 *
 * 										  	 36							
 * 								9		  	    			  27			
 * 						4				5	    		16		  		11	
 * 					1		3				    	7		  9				
 *(qs,qe)				
 * (0,5)=(0,5)						|			                    0(0,5)
 * (0,2)=(0,2)						|             1(0,2)							           2(3,5)
 * (0,3)=(0,2)+(3,3)	  	|	  	 3(0,1)				4(2,2)			    5(3,4)				6(5,5)
 * (0,4)=(0,2)+(3,4)			|  7(0,0)		8(1,1)					   11(3,3)		12(4,4)
 * (1,4)=(1,1)+(2,2)+(3,4)|	(1)			 (3)			(5)				 (5)			  (9)     (11)
 * (2,5)=(2,2)+(3,5)			|													
 *
 * Time Complexity
 *    Segment tree construction   O(n)
 *    Query                       O(logn)
 *    Update                      O(logn)
 */
/* st     -> segment tree array
 * index  -> root of the segment tree; (0)
 * ss, se -> segment start and end; (0, n-1)
 * qs, qe -> querry start and end
 */
int getSum(int *st, int index, int ss, int se, int qs, int qe)
{
  /* out of bound access */
  if(se < qs || qe < ss)
    return 0;

  /* within range access */
  if(qs <= ss && qe >= se) {
//    cout << ss << "," << se << " = " << st[index] << endl;
    return st[index];
  }

  int m = ss + (se - ss)/2;
  return getSum(st, 2*index + 1,  ss,  m, qs, qe) +
         getSum(st, 2*index + 2, m+1, se, qs, qe);
}

void updateValue(int *a, int *st, int index, int ss, int se, int pos, int val)
{
  if(pos < ss || se < pos)
    return;

  if(ss == se && ss == pos) {
    st[index] = val;
    return;
  }

  st[index] -= a[pos];
  int m = ss + (se - ss)/2;
  updateValue(a, st, 2*index + 1,  ss,  m, pos, val);
  updateValue(a, st, 2*index + 2, m+1, se, pos, val);
  st[index] += val;

  return;
}

void display(int *st, int n)
{
  for(int i = 0; i < n; ++i)
    cout << setw(3) << i;
  cout << endl;

  for(int i = 0; i < n; ++i)
    cout << setw(3) << st[i];
  cout << endl;
}

void constructSegTreeUtil(int *st, int i, int *a, int n)
{
  if(n < 2) {
    st[i] = a[0];
    return;
  }

  int m = (n + 1)/2;

  constructSegTreeUtil(st, 2*i+1, a, m);
  constructSegTreeUtil(st, 2*i+2, a + m, n - m);
  st[i] = st[2*i+1] + st[2*i+2];

  return;
}

int* constructSegTree(int *a, int n)
{
  int h = (int)(ceil(log2(n))); // height of segment tree
  int maxSize = 2*(int)(pow(2, h)) - 1; // max size of the segment tree

  int *st = (int *)malloc(maxSize * sizeof(int));
  memset(st, 0, maxSize * sizeof(int));

  constructSegTreeUtil(st, 0, a, n);

  display(st, maxSize);

  return st;
}

int main()
{
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr)/sizeof(arr[0]);

  int *st = constructSegTree(arr, n);
  display(arr, n);  
  int qs, qe; // querry start and end indexes

  qs = 1, qe = 1;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 2;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 3;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 4;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 5;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  
  updateValue(arr, st, 0, 0, n - 1, 1, 10);
  arr[1] = 10;
  cout << "updated the value at index 1 to 10" << endl;

  qs = 1, qe = 1;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 2;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 3;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 4;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;
  qs = 1, qe = 5;
  cout << "Sum of values in the range (" << qs << ", " << qe << "): " \
       << getSum(st, 0, 0, n - 1, qs, qe) << endl;

  return 0;
}
