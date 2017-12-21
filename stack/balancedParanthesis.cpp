#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isBalanced(string str) {
	unordered_map<char, char> char_map = {{')', '('}, {']', '['}, {'}', '{'}};
  stack<char> st;
  for(int j = 0; j < str.length(); ++j) {
    if('{' == str[j] || '[' == str[j] || '(' == str[j]) {
      st.push(str[j]);
    } else if('}' == str[j] || ']' == str[j] || ')' == str[j]) {
      if(st.empty() || char_map[str[j]] != st.top()) {
        return false;
      }
      st.pop();
    } else {
      return false;
    }
  }
  return st.empty();
}

vector<string> checkBalance(vector<string> &values)
{
  vector<string> res;
  for(int i = 0; i < values.size(); ++i) {
    isBalanced(values[i]) ?  res.push_back("YES") : res.push_back("NO");
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
