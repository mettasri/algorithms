#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<char> > getSubsetsIterative(vector<char> &set)
{
  vector<vector<char> > allSubsets;
  allSubsets.push_back(vector<char>(' '));

  vector<vector<char> > subsets;
  vector<char> subset;
  for(int i = 0; i < set.size(); ++i) {
    subsets = allSubsets;
    for(int it = 0; it < subsets.size(); ++it) {
      subset = subsets[it];
      subset.push_back(set[i]);
      allSubsets.push_back(subset);
    }
  }

  return allSubsets;
}

vector<vector<char> > getSubsetsRecursive(vector<char> &set, int i)
{
  if(set.size() == i) {
    vector<vector<char> > allSubsets;
    allSubsets.push_back(vector<char>(' '));
    return allSubsets;
  }

  int item = set[i];
  vector<vector<char> > allSubsets = getSubsetsRecursive(set, i + 1);
  vector<vector<char> > subsets(allSubsets);

  vector<char> subset;
  for(int it = 0; it < subsets.size(); ++it) {
    subset = subsets[it];
    subset.push_back(item);
    allSubsets.push_back(subset);
  }
  
  return allSubsets;
}

void allSubsetsOfSet(vector<char> &set, int i, string str)
{
  if("" == str) 
    cout << setw(3) << "{ }" << endl;
  else
    cout << setw(3) << str << endl;

  for(; i < set.size(); ++i) {
    allSubsetsOfSet(set, i + 1, str + set[i]);
  }
}

int main()
{
  char arr[] = {'1', '2', '3'};
  vector<char> set(arr, arr+sizeof(arr)/sizeof(arr[0]));
  allSubsetsOfSet(set, 0, "");

  vector<vector<char> > allSubsets = getSubsetsRecursive(set, 0);
  for(int i = 0; i < allSubsets.size(); ++i) {
    cout << "{";
    for(int j = 0; j < allSubsets[i].size(); ++j) {
      cout << allSubsets[i][j];
    }
    cout << "}" << endl;
  }
  cout << endl << endl;
  allSubsets = getSubsetsIterative(set);
  for(int i = 0; i < allSubsets.size(); ++i) {
    cout << "{";
    for(int j = 0; j < allSubsets[i].size(); ++j) {
      cout << allSubsets[i][j];
    }
    cout << "}" << endl;
  }
  return 0;
}
