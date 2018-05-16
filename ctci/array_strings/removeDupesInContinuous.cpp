#include <iostream>
#include <string>
using namespace std;

string removeContinuousDupes(string str)
{
  if(str == "") return "";
  if(str.size() < 2) return str;

  size_t r, w;
  char dupe = str[0];

  for(r = 1, w = 1; r < str.size(); ++r) {
    if(dupe != str[r])  {
      dupe = str[r];
      str[w] = str[r];
      ++w;
    }
  }
  str.resize(w);

  return str;
}

int main()
{
  "a"    == removeContinuousDupes("aaaaa")         ? cout << "PASS\n" : cout << "FAIL\n";
  "ab"   == removeContinuousDupes("aaaaabbbbbbb")  ? cout << "PASS\n" : cout << "FAIL\n";
  "abc"  == removeContinuousDupes("aaaaabbbbbbbc") ? cout << "PASS\n" : cout << "FAIL\n";
  "abcd" == removeContinuousDupes("aabccccdd")     ? cout << "PASS\n" : cout << "FAIL\n";
  "abcd" == removeContinuousDupes("abcd")          ? cout << "PASS\n" : cout << "FAIL\n";
}
