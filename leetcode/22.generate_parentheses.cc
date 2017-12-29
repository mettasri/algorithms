#include <iostream>
#include <vector>
using namespace std;

/*
 *                                                                       00
 *                                         ----------------------------------------------------------
 *                                        (10                                                       01)
 *               -------------------------------------------------------
 *              (20                                                   11)
 *   -------------------------                                  --------------
 *  (30                     21)                                 (21
 *    -----       ----------------------            ----------------------
 *       31)     (31                  22)          (31                  22)
 *        -----     ----        -------------   ---------           ----------
 *           32)      32)      (32                     32)         (32
 *            -----     -----    ----               ---------   ----------
 *               33)      33)      33)                      33)         33)
 *
 *  ((()))  10 20 30 31 32 33
 *  (()())  10 20 21 31 32 33
 *  (())()  10 20 21 22 32 33
 *  ()(())  10 11 21 31 32 33
 *  ()()()  10 11 21 22 32 33
 *
 */

/*
 * Time complexity: O( 4^n/sqrt(n) )
 * Space complexity: O( 4^n/sqrt(n) )
 *
 */
class Solution {
 public: 
  vector<string> generateParentheses(int n) {
    if (n == 0) return {};

    vector<string> res;
    generateAll(res, "", 0, 0, n);

    return res;
  }

 private:
  void generateAll(vector<string> &res, string str, int open, int close, int n) {
    if (str.size() == n * 2) {
      res.push_back(str);
      return;
    }

    if (open < n)
      generateAll(res, str + "(", open + 1, close, n);
    if (close < open)
      generateAll(res, str + ")", open, close + 1, n);
  }
};

void display(vector<string> &v) {
  for (string str : v) {
    cout << str << endl;
  }
}

int main() {
  Solution s;
  vector<string> res;

  res = s.generateParentheses(3);
  display(res);
}
