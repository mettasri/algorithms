#include <iostream>
#include <string>
using namespace std;

bool isS1RotationOfS2(string s1, string s2)
{
  string s11 = s1 + s1;

  size_t found = s11.find(s2);
  if(found != string::npos)
    return true;
  return false;
}

int main()
{
  true == isS1RotationOfS2("waterbottle", "erbottlewat") ? cout << "PASS\n" : cout << "FAIL\n";
  false == isS1RotationOfS2("waterbottle", "erbttlewat") ? cout << "PASS\n" : cout << "FAIL\n";
}
