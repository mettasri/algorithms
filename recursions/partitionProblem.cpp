#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;

/*
												0, 1, 2, 3
							3																3							
			2								2								2								2			
	1				1				1				1				1				1				1				1	
0		0		0		0		0		0		0		0		0		0		0		0		0		0		0		0

 3 2 1 0
 3 2 1
 3 2 0
 3 2
 3 1 0
 3 1
 3 0
 3
 2 1 0
 2 1
 2 0
 2
 1 0
 1
 0

 Time complexicity: O(2^n)
*/

bool isPartitionEqualUtil(vector<int> v, int n, int sum, vector<int> res)
{
  if(0 == sum) return true;
  if(0 == n) return false;

  return isPartitionEqualUtil(v, n - 1, sum - v[n - 1], res) || 
         isPartitionEqualUtil(v, n - 1, sum, res);
}

bool isPartitionEqual(vector<int>& v)
{
  int sum = 0;
  vector<int> res;
  sum = accumulate(v.begin(), v.end(), sum);
  if(sum % 2 != 0) // sum is odd
    return false;
  return isPartitionEqualUtil(v, v.size(), sum/2, res);
}

int main()
{
  int arr[] = {1, 5, 11, 5};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

  cout << isPartitionEqual(v);

  return 0;
}
