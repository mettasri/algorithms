#include <iostream>
#include <vector>
#include <string>
using namespace std;

string removeDuplicateCharInString(string str) {
//  search from start index to write index
//  if it exists, then ignore
//  else append at write point
  if(str == "")
    return "";

  int r, w, i;
  for(r = 1, w = 1; r < str.length(); ++r) {
    for(i = 0; i < w; ++i)  {
      if(str[r] == str[i])
        break;
    }
    if(i == w)
      str[w++] = str[r];
  }
  str.resize(w);

  return str;
}

int main() {
//  removeDuplicateCharInString("hellow world").compare("helow rd") == 0 ? cout << "PASS\n" : cout << "FAIL\n";
  "helow rd" == removeDuplicateCharInString("hellow world") ? cout << "PASS\n" : cout << "FAIL\n";
  "abcd"     == removeDuplicateCharInString("abcd")         ? cout << "PASS\n" : cout << "FAIL\n";
  "ab"       == removeDuplicateCharInString("aaabbb")       ? cout << "PASS\n" : cout << "FAIL\n";
  "a"        == removeDuplicateCharInString("aaaa")         ? cout << "PASS\n" : cout << "FAIL\n";
  ""         == removeDuplicateCharInString("")             ? cout << "PASS\n" : cout << "FAIL\n";
}
