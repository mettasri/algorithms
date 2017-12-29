#include <iostream>
#include <vector>
using namespace std;

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
