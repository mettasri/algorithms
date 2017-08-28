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
    // counts unique chars
    if(0 == chars[str1[i]]) uniqueChars++;

    chars[str1[i]]++;
  }

  // Process string2
  for(i = 0; i < str2.length(); ++i) {
    if(0 == chars[str2[i]]) return false;

    chars[str2[i]]--;

    if(0 == chars[str2[i]]) {
      uniqueChars--;
      //if(uniqueChars == 0)
      //  return i == (str2.length() - 1);
    }
  }
  return 0 == uniqueChars && i == str2.length();
//  return false;
}

int main() {
    isAnagramStrings("abcd", "bcad")      ? cout << "PASS\n" : cout << "FAIL\n";
  ! isAnagramStrings("abce", "bcad")      ? cout << "PASS\n" : cout << "FAIL\n";
  ! isAnagramStrings("abc", "bcad")       ? cout << "PASS\n" : cout << "FAIL\n";
    isAnagramStrings("abacbb", "bcbaba")  ? cout << "PASS\n" : cout << "FAIL\n";
  ! isAnagramStrings("abacbb", "bcbabad") ? cout << "PASS\n" : cout << "FAIL\n";
}
