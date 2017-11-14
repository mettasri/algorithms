#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

int length_longest_substr(const string& s) {
  map<char, int> char_map;
  int ans = 0;
  for (int j = 0, i = 0; j < s.size(); ++j) {
    if (char_map.end() != char_map.find(s[j])) {
      i = max(char_map[s[j]], i);
      cout << "i " << i << " j " << j << endl;
    }
    ans = max(j - i + 1, ans);
    char_map.insert(make_pair(s[j], (j + 1)));
  }

  return ans;
}

int main() {
  cout << length_longest_substr("abca") << endl;
  cout << length_longest_substr("abcad") << endl;
  
  return 0;
}
