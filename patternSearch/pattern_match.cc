#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int followPatern(string pattern, string example) {
  map<string, string> strMap;
  map<string, string> ::iterator it;
  istringstream issEx(example), issPat(pattern);
  string pat, ex;

  while(getline(issEx, ex, ' ') && getline(issPat, pat, ' ')) {
    it = strMap.find(ex);
    if(it != strMap.end()) {
      if(it->second != pat)
        return 0;
    } else {
      cout << ex << " " << pat << endl;
      strMap.insert(it, pair<string, string>(ex, pat));
    }
  }

  return 1;
}

int main()
{
  followPatern("a b b a", "cat dog dog cat") ? cout << "true\n" : cout << "false\n";
  followPatern("a b b a", "dog dog cat dog") ? cout << "true\n" : cout << "false\n";
}
