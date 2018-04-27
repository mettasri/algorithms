#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <climits>
using namespace std;

class TallPeople {
public:
  void parse(vector<string> const &people, vector<vector<int>> &ppl) {
    vector<int> t;

    for(auto str: people) {
      t.clear();
      stringstream ss(str);
      copy(istream_iterator<int>(ss), istream_iterator<int>(), back_inserter(t));
      ppl.push_back(t);
    }
  }

  int tallest_of_the_shortest(vector<vector<int>> const &ppl) {
    int tallest = INT_MIN;
    int shortest = INT_MAX;

    for(auto row : ppl) {
      shortest = INT_MAX;
      for(auto p : row) {
        if(shortest > p) shortest = p;
      }
      if(tallest < shortest) tallest = shortest;
    }
    return tallest;
  }

  int shortest_of_the_tallest(vector<vector<int>> const &ppl) {
    int tallest = INT_MIN;
    int shortest = INT_MAX;

    for(int c = 0; c < ppl[0].size(); c++) {
      tallest = INT_MIN;
      for(int r = 0; r < ppl.size(); r++) {
        if(tallest < ppl[r][c]) tallest = ppl[r][c];
      }
      if(shortest > tallest) shortest = tallest;
    }
    return shortest;
  }

  vector<int> getPeople(vector<string> const &people) {
    vector<vector<int>> ppl;
    vector<int> res;
    
    parse(people, ppl);
    
    // short in row then tall in col
    res.push_back(tallest_of_the_shortest(ppl));
    // tall in col then short in row
    res.push_back(shortest_of_the_tallest(ppl));

    return res;
  }
};
