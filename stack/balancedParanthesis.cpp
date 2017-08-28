#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> checkBalance(vector<string> &values)
{
  char ch;
  int i, j;
  string str = "";
  vector<string> res;
  stack<char> st;
  
  for(i = 0; i < values.size(); ++i) {
    str = values[i];
    st.empty();
    for(j = 0; j < str.length(); ++j) {
      if('{' == str[j] || '[' == str[j] || '(' == str[j]) {
        st.push(str[j]);
      } else if('}' == str[j] || ']' == str[j] || ')' == str[j]) {
        if(st.empty()) {
          cout << "stack empty " << j << endl;
          res.push_back("NO");
          break;
        }
        ch = st.top();
        st.pop();
        if((ch == '{' && '}' != str[j]) || 
           (ch == '[' && ']' != str[j]) || 
           (ch == '(' && ')' != str[j])) {
          cout << " stack top is not balanced " << j << endl;
          res.push_back("NO");
          break;
        }
      }
    }
    if(! st.empty()) {
      cout << "stack not empty " << endl;
      res.push_back("NO");
    }
    else if(j == str.length()) {
      res.push_back("YES");
    }
  }

  return res;
}

int main()
{
  vector<string> values;
  vector<string> res;
  values.push_back("[{}]()[{{()}}()]");
  values.push_back("[{}]({{()}}()]");

//  for(int i = 0; i < values.size(); ++i)
//    cout << values[i] << endl;
  res = checkBalance(values);
  for(int i = 0; i < res.size(); ++i)
    cout << res[i] << endl;
}
