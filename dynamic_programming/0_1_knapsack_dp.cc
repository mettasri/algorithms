#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Solution2: Dynamic Programming approach
// The above solution is Overlapping Subproblems property
// Time complexity = O(n^2)

/*        j-> weights (max = 7)
 * val wt 0 1 2 3 4 5 6 7
 *     0  0 0 0 0 0 0 0 0
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
  int n = wt.size();
  vector<vector<int>> k(n + 1, vector<int>(W + 1, 0));
  for (int i = 0; i <= n; ++i) { // Given weights
    for (int w = 0; w <= W; ++w) { // Possible weight capacity
      if (i == 0 || w == 0)
        k[i][w] = 0;
      else if (w < wt[i - 1])
        k[i][w] = k[i - 1][w];
      else
        k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
      cout << setw(2) << k[i][j];
    }
    cout << endl;
  }
  return k[n][W];
}

int main() {
  vector<int> weights{1, 3, 4, 5};
  vector<int> values {1, 4, 5, 7};
  // Knapsack_capacity
  int W = 7;

  cout << knapsack(weights, values, W) << endl;
}
