#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (!nums.size()) return 0;

    sort(nums.begin(), nums.end());
    int j, k, len = nums.size(), sum;
    int close_sum = 0;
    int min_dist = numeric_limits<int>::max();
    for (int i = 0; i < len; i++) {
      j = i + 1;
      k = len - 1;
      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        int dist = abs(sum - target);
        if (dist < min_dist) {
          min_dist = dist;

          close_sum = sum;
          if (close_sum == target) return target;
        }
        (sum > target) ? k-- : j++;
      }
    }
    return close_sum;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 2, 1, -4};
  2 == s.threeSumClosest(nums, 1) ? cout << "PASS\n" : cout << "FAIL\n";
}
