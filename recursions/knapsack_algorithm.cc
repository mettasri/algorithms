/*
 * Weights : 2 3 3 4
 * Values  : 1 2 5 9
 * Knapsack Capacity (W) = 7
 * 
 *                                                         (0,1,2,3)
 *                           3(0,1,2)                                                        (0,1,2)
 *             3,2(0,1)                      3(0,1)                           2(0,1)                   (0,1)
 *      3,2,1(0)       3,2(0)          3,1(0)        3(0)               2,1(0)      2(0)          1(0)        (0)
 * 3,2,1,0   3,2,1   3,2,0   3,2   3,1,0   3,1      3,0  3         2,1,0   2,1   2,0   2        1,0   1      0
 * 
 * 
 * 
 * 
 *                                                         (W=7)
 *                           3(W=3)                                                        (W=7)
 *             3,2(W=0)                      3(W=3)                           2(W=4)                   (W=7)
 *      3,2,1(0)       3,2(0)        3,1(W=0)       3(W=3)           2,1(W=1)     2(W=4)         1(W=4)        (W=7)
 * 3,2,1,0   3,2,1   3,2,0   3,2   3,1,0   3,1      3,0  3         2,1,0   2,1   2,0   2        1,0   1      0
 *                                                  w=1  w=3       
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
// Solution: naive recursive approach
// runtime complexity s O(2^n)
//
int knapsack(vector<int>& weights, vector<int>& values, int W, int n) {
  if (W == 0 || n == 0) {
    return 0;
  }

  if (weights[n - 1] > W) {
    // dont include current value
    return knapsack(weights, values, W, n - 1);
  }
                             /* include the current index value */
  return max(values[n - 1] + knapsack(weights, values, W - weights[n - 1], n - 1),
                             /* dont include the current index value */
                             knapsack(weights, values, W, n - 1));
}

int main() {
  vector<int> weights{2, 3, 3, 4};
  vector<int> values {1, 2, 5, 9};
  //Knapsack_capacity
  int W = 7;
  int n = sizeof(weights)/sizeof(weights[0]);

  cout << "max values: " << knapsack(weights, values, W, n) << endl;
}

// Solution2: Dynamic Programming approach
// The above solution is Overlapping Subproblems property
