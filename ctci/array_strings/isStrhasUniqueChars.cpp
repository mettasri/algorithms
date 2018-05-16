#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isStringHasUniqueChars(string str)
{
  vector<bool> chars(256, 0);
  
  for(int i = 0; i < str.length(); i++) {
    if(chars[str[i]])
      return false;
    chars[str[i]] = true;
  }
  return true;
}

int main()
{
  ! isStringHasUniqueChars("hello world") ? cout << "PASS\n" : cout << "FAIL\n";
  ! isStringHasUniqueChars("helo world")  ? cout << "PASS\n" : cout << "FAIL\n";
    isStringHasUniqueChars("helo wrd")    ? cout << "PASS\n" : cout << "FAIL\n";
}
