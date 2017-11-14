#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Solution2: Dynamic Programming approach
// The above solution is Overlapping Subproblems property
// Time complexity = O(n^2)

/*        j-> weights
 * val wt 0 1 2 3 4 5 6 7
 *        0 0 0 0 0 0 0 0
 * (1) 1  0 1 1 1 1 1 1 1
 * (4) 3  0 1 1 4 5 5 5 5
 * (5) 4  0 1 1 4 5 6 6 9
 * (7) 5  0 1 1 4 5 7 8 9
 * 
 * if j < wt[i]:
 *   k[i][j] = k[i - 1][j]
 * else:
 *   k[i][j] = max(include_current_weight,
 *                 not_include_current_weight)
 *           = max(val[i - 1] + k[i - 1][j - wt[i - 1]],
 *                 k[i - 1][j])
 */

int knapsack(vector<int>& wt, vector<int>& val, int W) {
  int r = wt.size() + 1;
  int c = W + 1;
  vector<vector<int>> k(r, vector<int>(c, 0));
  for (int i = 0; i < r; ++i) { // given weights
    for (int j = 0; j < c; ++j) { // possible weight capacity
      if (i == 0 || j == 0) {
        k[i][j] = 0;
      } else if (j < wt[i - 1]) {
        k[i][j] = k[i - 1][j];
      } else {
        k[i][j] = max(val[i - 1] + k[i - 1][j - wt[i - 1]],
                      k[i - 1][j]);
      }
    }
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << setw(2) << k[i][j];
    }
    cout << endl;
  }
  return k[r - 1][c - 1];
}

int main() {
  vector<int> weights{1, 3, 4, 5};
  vector<int> values {1, 4, 5, 7};
  //Knapsack_capacity
  int W = 7;

  cout << knapsack(weights, values, W) << endl;
}

