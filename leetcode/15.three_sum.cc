#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int target, start, end, sum;
    for (int i = 0; i < (nums.size() - 2); ++i) {
      if (nums[i] > 0) break; // all are positive nums
      if (i && nums[i - 1] == nums[i]) continue;

      target = -nums[i];
      start = i + 1, end = nums.size() - 1;
      while (start < end) {
        sum = nums[start] + nums[end];
        if (sum < target) {
          start++;
        } else if (sum > target) {
          end--;
        } else {
          // duplicate detection
          if (start == 0 || nums[start - 1] != nums[start]|| 
              end == nums.size() - 1 || nums[end + 1] != nums[end]) {
            res.push_back(vector<int> {nums[i], nums[start], nums[end]});
          }
          start++; end--;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> res;

  //vector<int> nums = {-1, 0, 1, 2, -1, -4, 1, 2};
  vector<int> nums = {-4, -1, -1, -1, 0, 1, 1, 2, 2};
  //vector<int> nums = {0, 0, 0};
  res = s.threeSum(nums);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
