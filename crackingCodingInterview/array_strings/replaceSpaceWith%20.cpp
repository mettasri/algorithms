#include <iostream>
#include <string>
using namespace std;

string replaceSpaceWithPercent20(string str)
{
  size_t spaceCount = 0;
  int len, newLen, i;

  len = str.length();
  for(i = 0; i < len; ++i) {
    if(' ' == str[i])  {
      spaceCount++;
    }
  }

  newLen = len + (spaceCount * 2);

  str.resize(newLen);

  for(i = len - 1; i >= 0; --i) {
    if(' ' == str[i])  {
      str[newLen - 1]   = '0';
      str[newLen - 2] = '2';
      str[newLen - 3] = '%';
      newLen -= 3;
    } else  {
      str[newLen - 1] = str[i];
      newLen--;
    }
  }

  return str;
}

int main()
{
  replaceSpaceWithPercent20("hello world")    == "hello%20world"          ? cout << "PASS\n" : cout << "FAIL\n";
  replaceSpaceWithPercent20(" hello world ")  == "%20hello%20world%20"    ? cout << "PASS\n" : cout << "FAIL\n";
  replaceSpaceWithPercent20(" hello  world ") == "%20hello%20%20world%20" ? cout << "PASS\n" : cout << "FAIL\n";
  replaceSpaceWithPercent20(" ")              == "%20"                    ? cout << "PASS\n" : cout << "FAIL\n";

  return 0;
}
