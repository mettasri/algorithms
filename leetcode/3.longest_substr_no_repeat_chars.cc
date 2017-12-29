#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (!s.size())  return 0;
    unordered_map<char, int> char_map;
    int left = 0, longest = 0, right = 0;
    for (right = 0; right < s.size(); right++) {
      // duplicate found
      if (char_map.find(s[right]) != char_map.end()) {
        left = max(char_map[s[right]] + 1, left);
      }
      char_map[s[right]] = right;
      longest = max(longest, right - left + 1);
    }
    return longest;
  } 
};

int main() {
  Solution sol;
  sol.lengthOfLongestSubstring("pwwkew") == 3 ? cout << "PASS\n" : cout << "FAIL\n";
  sol.lengthOfLongestSubstring("pwwkpew") == 4 ? cout << "PASS\n" : cout << "FAIL\n";

  sol.lengthOfLongestSubstring("abcabcbb") == 3 ? cout << "PASS\n" : cout << "FAIL\n";
  sol.lengthOfLongestSubstring("bbbbb") == 1 ? cout << "PASS\n" : cout << "FAIL\n";
  
}
