#include <iostream>
#include <vector>
using namespace std;

/*
 * Generates 2^(2n) sequences
 * Validating sequence O(n)
 *
 * Time complexity: O(n*2^2n)
 * Space complexity: O(n*2^2n)
 *
 */

class Solution {
 public: 
  vector<string> generateParentheses(int n) {
    if (n == 0) return {};

    vector<string> res;
    generateAll(res, "", 2 * n);

    return res;
  }

 private:
  void generateAll(vector<string> &res, string str, int n) {
    if (str.size() == n) {
      if (valid(str)) {
        res.push_back(str);
      }
      return;
    }

    generateAll(res, str + "(", n);
    generateAll(res, str + ")", n);
  }
  
  bool valid(string &str) {
    int balance = 0;

    for (char ch : str) {
      if (ch == '(')  balance++;
      else  balance--;

      if (balance < 0)  return false;
    }
    return (balance == 0);
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
