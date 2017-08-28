#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

int evaluatePostfixExp(string exp)
{
  if(exp.empty())
    return -1;

  stack<int> st;
  int val1, val2;
  for(int i = 0; i < exp.length(); i = i + 2) {
    if(exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-') {
      val1 = st.top(); st.pop();
      val2 = st.top(); st.pop();
      if(exp[i] == '*') {
        val1 = val2 * val1;
      } else if(exp[i] == '/') {
        val1 = val2 / val1;
      } else if(exp[i] == '+') {
        val1 = val2 + val1;
      } else if(exp[i] == '-') {
        val1 = val2 - val1;
      }
    } else {
      val1 = atoi(exp.substr(i).c_str());
    }
    st.push(val1);
  }
//  cout << st.top() << endl;
  return st.top();
}

int main()
{
  14 == evaluatePostfixExp("2 3 4 * +") ? cout << "PASS\n" : cout << "FAIL\n";
  21 == evaluatePostfixExp("1 2 + 7 *") ? cout << "PASS\n" : cout << "FAIL\n";
  -4 == evaluatePostfixExp("2 3 1 * + 9 -") ? cout << "PASS\n" : cout << "FAIL\n";
  
  return 0;
}
