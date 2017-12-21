#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> value_index_map;
    for (int i = 0; i < nums.size(); ++i) {
      int remain = target - nums[i];
      const auto it = value_index_map.find(remain);
      if (it != value_index_map.end()) {
        return vector<int>{it->second, i};
      }
      value_index_map.emplace(nums[i], i);
    }
    return vector<int>{};
  }
};

int main() {
  Solution s;
  //vector<int> nums = {2, 7, 11, 15};
  vector<int> nums = {7, 11, 15, 2};
  vector<int> res = s.twoSum(nums, 9);
  for (int num : res)
    cout << num << " ";
  cout << endl;
}
