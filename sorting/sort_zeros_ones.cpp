#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;

void sortVector(vector<int> &v) {
  int n, z;

  for(n = 0, z = 0; z < v.size(); z++) {
    if(v[z] == 0) {
      int temp = v[z];
      v[z] = v[n];
      v[n] = temp;
      n++;
    }
  }
}

int main() {
  vector<int> v { 1, 0, 1, 1, 0, 0, 1, 1 };
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  sortVector(v);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
