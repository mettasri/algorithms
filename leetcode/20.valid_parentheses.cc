#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
 public:
  bool validParentheses(string str) {
		unordered_map<char, char> char_map = {{')', '('}, {']', '['}, {'}', '{'}};

		stack<char> st;
		for (int i = 0; i < str.size(); ++i) {
			// push
			char ch = str[i];
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			} else if (ch == ')' || ch == ']' || ch == '}') { // pop
				if (st.empty() || char_map[ch] != st.top()) {
					return false;
				}
				st.pop();
			} else {
				return false;
			}
		}
		return st.empty();
  }
};

int main() {
	Solution s;
	true == s.validParentheses("()[]{}") ? cout << "PASS\n" : cout << "FAIL\n";
	false == s.validParentheses("(]") ? cout << "PASS\n" : cout << "FAIL\n";
	false == s.validParentheses("()]") ? cout << "PASS\n" : cout << "FAIL\n";
	false == s.validParentheses("(()[]") ? cout << "PASS\n" : cout << "FAIL\n";
}
