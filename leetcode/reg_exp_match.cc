Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Solution 1: recursive approach (method 1)
(s, p)
       --- if p is empty => return s is empty
       
       --- if p[1] == '*'  ----  if !s.empty and (s[0] == p[0] or p[0] == '.')  => left = (s[1:], p) // s = 'aa', p = '.*' => s = 'a', p = '.*'
                           ----  right = (s, p[2:]) // s = '', p = '.*' => s = '', p = ''
                           return (left || right)

       --- if !s.empty and (p[0] == s[0] or p[0] == '.') => return (s[1:], p[1:]) // s = 'aa', p = 'ab' => s = 'a', p = 'b'

Solution 1: recursive approach (method 2)
(s, p)
       --- if p is empty => return s is empty

       --- if !s.empty and (s[0] == p[0] or p[0] == '.')
             if p[1] == '*' => if (s[1:], p) return true
                            => if (s, p[2:])  return true
             else           if (s[1:], p[1:])  return true
       --- return false

Solution 2: Dynamic programming

