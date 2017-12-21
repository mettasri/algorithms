/*
 * Leetcoder: Regular Expression Matching
 * 
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 *
 * Solution 1: recursive approach (method 1)
 * 
 * BaseCase:
 *   s      p    result
 *   null  null   TRUE
 *  !null  null   FALSE
 * 
 * RecursiveCase:
 *                       (s,p)                 
 *         -------------------------------
 *        |                |              |
 *        |                |              |
 *    p[1]=='*'          first          first    
 *    --------           equal          not equal
 *    |      |           (s+1,p+1)       (FALSE)
 *    |      |
 *  first   first
 *  equal   not equal
 *  (s+1,p) (s,p+2)
 */

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const string s, const string p) {
  // base case
  if (p.empty())  return s.empty();
  
  if (p.size() > 1 && p[1] == '*') {
    return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)) ||
            isMatch(s, p.substr(2));
  }
  return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));

  return false;

}

int main() {
  isMatch("aa", "a") == false ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aa", "aa") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aaa", "aa") == false ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aa", "a*") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aa", ".*") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("ab", ".*") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aab", "c*a*b") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aab", "c*d*aab") == true ? cout << "PASS\n" : cout << "FAIL\n";
  isMatch("aab", "ac*ab") == true ? cout << "PASS\n" : cout << "FAIL\n";
  
  return 0;
}


/* 
 *Solution 2: Dynamic Programming
 *   p-- 
 * s   0 1 2 3
 * | 0 1 0
 *   1 0
 *   2 0
 *   3 0
 *
 */
