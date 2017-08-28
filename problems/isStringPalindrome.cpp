#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
  int len = str.length();

  for(int i = 0; i < len/2; ++i) {
    if(str[i] != str[len - 1 - i])
      return false;
  }
  return true;
}

bool isPalindromeRecursive(string str, int l, int r)
{
  if(l == r) return true;
  if(((l + 1) == r) && (str[l] == str[r])) return true;
  
  return (str[l] == str[r] && isPalindromeRecursive(str, l + 1, r - 1));
}

int main()
{
//  true  == isPalindrome("MALAYALAM")? cout << "PASS\n" : cout << "FAIL\n";
//  false == isPalindrome("MALAYALA")? cout << "PASS\n" : cout << "FAIL\n";
//  true  == isPalindrome("ABBA")? cout << "PASS\n" : cout << "FAIL\n";
//  false == isPalindrome("ABBB")? cout << "PASS\n" : cout << "FAIL\n";

  true  == isPalindromeRecursive("MALAYALAM", 0, 8)? cout << "PASS\n" : cout << "FAIL\n";
  false == isPalindromeRecursive("MALAYALA", 0, 7)? cout << "PASS\n" : cout << "FAIL\n";
  true  == isPalindromeRecursive("ABBA", 0, 3)? cout << "PASS\n" : cout << "FAIL\n";
  false == isPalindromeRecursive("ABBB", 0, 3)? cout << "PASS\n" : cout << "FAIL\n";
}
