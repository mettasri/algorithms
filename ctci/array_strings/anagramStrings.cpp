#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagramStrings(string str1, string str2) {
  if(str1.length() != str2.length()) return false;

  vector<size_t> chars(256, 0);
  size_t uniqueChars = 0, i;

  // Process string1
  for(i = 0; i < str1.length(); ++i) {
    if(0 == chars[str1[i]]) uniqueChars++;
    chars[str1[i]]++;
  }

  // Process string2
  for(i = 0; i < str2.length(); ++i) {
    if(0 == chars[str2[i]]) return false;
    chars[str2[i]]--;
    if(0 == chars[str2[i]]) {
      uniqueChars--;
    }
  }
  return 0 == uniqueChars && i == str2.length();
}

int main() {
  isAnagramStrings("abcd", "bcad")      ? cout << "PASS\n" : cout << "FAIL\n";
  isAnagramStrings("abce", "bcad")      ? cout << "FAIL\n" : cout << "PASS\n";
  isAnagramStrings("abc", "bcad")       ? cout << "FAIL\n" : cout << "PASS\n";
  isAnagramStrings("abacbb", "bcbaba")  ? cout << "PASS\n" : cout << "FAIL\n";
  isAnagramStrings("abacbb", "bcbabad") ? cout << "FAIL\n" : cout << "PASS\n";
}
