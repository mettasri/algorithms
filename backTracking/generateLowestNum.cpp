#include <iostream>
#include <cstdlib>
using namespace std;

/* Given a string ‘str’ of digits and an integer ‘n’, 
 * build the lowest possible number by removing ‘n’ 
 * digits from the string and not changing the order of input digits.
 */
string generateLowestNum(string str, int n)
{
  if(str == "" || n == 0) {
    cout << str << endl;
    return str;
  }

  string lowNum = "";
  for(int i = 0; i < str.length(); i++)
  {
    string temp = str;
    string ret;

    str = str.substr(0, i) + str.substr(i + 1, (str.length() - i - 1));
//    cout << str << endl;
    ret = generateLowestNum(str, n - 1);
    if(lowNum == "" || (atoi(ret.c_str()) < atoi(lowNum.c_str())))
      lowNum = ret;

    str = temp;
  }
//  cout << lowNum << endl;
  return (lowNum);
}

int main()
{
//  generateLowestNum("4205123", 4) == "012" ? cout << "PASS \n" : cout << "FAIL\n";
  generateLowestNum("1234", 1) == "123" ? cout << "PASS \n" : cout << "FAIL\n";
//  generateLowestNum("216504", 3) == "104" ? cout << "PASS \n" : cout << "FAIL\n";
//  generateLowestNum("2200010300", 4) == "000000" ? cout << "PASS \n" : cout << "FAIL\n";
//  generateLowestNum("", 2) == "" ? cout << "PASS \n" : cout << "FAIL\n";
}
