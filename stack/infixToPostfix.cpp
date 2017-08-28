#include <iostream>
#include <stack>
using namespace std;

int opPre(char ch)
{
  char pre;
  switch(ch) {
    case '+':
    case '-':
      pre = 1;
      break;
    
    case '*':
    case '/':
      pre = 2;
      break;
    
    case '^':
      pre = 3;
      break;

    default:
      pre = -1;
  }
  return pre;
}

bool isOperand(char ch)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '^')
    return false;
  return true;
}

string convertInfixToPostfix(string exp)
{
  if(exp.empty())
    return "";

  stack<char> st;
  string res;
  char val;
  for(int i = 0; i < exp.length(); ++i) {
    val = exp[i];
    if(isOperand(val)) {
      res = res + val;
    } else if(val == '(') {
      st.push(val);
    } else if(val == ')') {
      while(! st.empty()) {
        if(st.top() == '(') {
          st.pop();
          break;
        }
        res = res + st.top();
        st.pop();
      }
    } else {
      while(! st.empty() && opPre(val) <= opPre(st.top())) {
        res = res + st.top();
        st.pop();
      }
      st.push(val);
    }
  }
  while(! st.empty()) {
    res = res + st.top();
    st.pop();
  }
  return res;
}

int main()
{
  string res;
  res = convertInfixToPostfix("2+3*4");
  if (! res.compare(string("234*+"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("a*b+5");
  if (! res.compare(string("ab*5+"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("(1+2)*7");
  if (! res.compare(string("12+7*"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("a*b/c");
  if (! res.compare(string("ab*c/"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("(a/(b-c+d))*(e-a)*c");
  if (! res.compare(string("abc-d+/ea-*c*"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("a/b-c+d*e-a*c");
  if (! res.compare(string("ab/c-de*+ac*-"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;

  res = convertInfixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
  if (! res.compare(string("abcd^e-fgh*+^*+i-"))) cout << "PASS\n"; else cout << "FAIL: " << res << endl;
}
