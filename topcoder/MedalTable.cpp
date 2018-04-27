#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
using namespace std;

bool compare(string str1, string str2);

class MedalTable {
public:
  static map<string, vector<int>> medalMap;
  vector<string> generate(vector<string> const &results) {
    vector<string> res;
    vector<int> mapVal(3, 0);
    vector<string> sortedRes;
    
    for(auto raw_str : results) {
      vector<string> str;
      stringstream ss(raw_str);
      copy(istream_iterator<string>(ss), istream_iterator<string>(), 
            back_inserter(str));

      for(int i = 0; i < str.size(); i++) {
        if(medalMap.end() == medalMap.find(str[i])) {
          medalMap.insert(pair<string, vector<int>>(str[i], mapVal));
          sortedRes.push_back(str[i]);
        }
        medalMap[str[i]][i]++;
      }
    }

    sort(sortedRes.begin(), sortedRes.end(), compare);

    for(auto str : sortedRes) {
      string s;
      stringstream ss;
      copy(medalMap[str].begin(), medalMap[str].end(), ostream_iterator<int>(ss, " "));
      s = ss.str();
      s.pop_back(); // erase last space, added by copy
      res.push_back(str + " " + s);
    }

    return res;
  }
};

map<string, vector<int>> MedalTable:: medalMap;

bool compare(string str1, string str2) {
  for(int i = 0; i < MedalTable::medalMap[str1].size(); i++) {
    if(MedalTable::medalMap[str1][i] < MedalTable::medalMap[str2][i]) {
      return false;
    } else if(MedalTable::medalMap[str1][i] > MedalTable::medalMap[str2][i]) {
      return true;
    } 
  }
  return str1 < str2;
}


