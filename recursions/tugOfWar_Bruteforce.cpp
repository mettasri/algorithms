#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
using namespace std;
/*
   0  1 2  3 4 5
  23 12 5 10 8 1
                                                                0                                                              
																1																																1															
								2																2																2																2							
				3								3								3								3								3								3								3								3			
		4				4				4				4				4				4				4				4				4				4				4				4				4				4				4				4	
	5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5		5

	5			3				2						    1																0								0								0	1					    0	1	2			
	4			3	5			2	5					    1	5															0	5							0	2							0	1	5				    0	1	2	5		
	4	5		3	4			2	4					    1	4															0	4							0	2	5						0	1	4				    0	1	2	4		
				3	4	5		2	4	5				    1	4	5														0	4	5						0	2	4						0	1	4	5			    0	1	2	4	5	
								2	3					    1	3															0	3							0	2	4	5					0	1	3				    0	1	2	3		
								2	3	5				    1	3	5														0	3	5						0	2	3						0	1	3	5			    0	1	2	3	5	
								2	3	4				    1	3	4														0	3	4						0	2	3	5					0	1	3	4			    0	1	2	3	4	
								2	3	4	5			    1	3	4	5													0	3	4	5					0	2	3	4					0	1	3	4	5		    0	1	2	3	4	5
														    1	2																							0	2	3	4	5																
														    1	2	5																																											
														    1	2	4																																											
														    1	2	4	5																																										
														    1	2	3																																											
														    1	2	3	5																																										
														    1	2	3	4																																										
														    1	2	3	4	5																																									
 Time Complexicity = O(2^n)
                     Exponential
*/

void halfPartisionMinDiffUtil(int i, vector<int>& vec, vector<bool>& includeList, vector<bool>& sol, 
    int includeCount, int curSum, int& sum, int& minDiff)
{
  // array out of bound access
  if(i >= vec.size()) return;
  
  // not more than half of total elements to be considered
  if(includeCount >= vec.size()/2) return;

  halfPartisionMinDiffUtil(i + 1, vec, includeList, sol, includeCount, curSum, sum, minDiff);

  includeList[i] = true;
  includeCount++;
  curSum += vec[i];

  // check for minDiff only when half of the elements are considered
  if((includeCount == vec.size()/2) && (minDiff > abs(sum/2, curSum))) {
    minDiff = abs(sum/2, curSum);
    for(int j = 0; j < includeList.size(); ++j)
      sol[j] = includeList[j];
    cout << "minDiff: " << minDiff << endl;
  }

  halfPartisionMinDiffUtil(i + 1, vec, includeList, sol, includeCount, curSum, sum, minDiff);
  includeList[i] = false;
}

void halfPartisionMinDiff(vector<int>& vec, vector<bool>& includeList, vector<bool>& sol)
{
  int minDiff = INT_MAX;
  int sum = 0, curSum = 0, includeCount = 0;
  
  for(int i = 0; i < vec.size(); ++i) {
    sum += vec[i];
  }
  halfPartisionMinDiffUtil(0, vec, includeList, sol, includeCount, curSum, sum, minDiff);
}

int main()
{
//  int arr[] = {23, 12, 5, 10, 8, 1}
  int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> vec(arr, arr+n);
  vector<bool> includeList(n, false);
  vector<bool> sol(n, false);

  halfPartisionMinDiff(vec, includeList, sol);

  cout << "List1: ";
  for(int i = 0; i < n; ++i) {
    if(sol[i])
      cout << setw(4) << vec[i];
  }
  cout << endl;
  cout << "List2: ";
  for(int i = 0; i < n; ++i) {
    if(!sol[i])
      cout << setw(4) << vec[i];
  }
  cout << endl;

  return 0;
}
