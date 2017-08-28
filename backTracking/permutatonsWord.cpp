#include <iostream>
using namespace std;

void permutationsOfWord(string str, int index)
{
  if(index == str.size()) {
    cout << str << endl;
    return;
  }

  for(int i = index; i < str.size(); i++) {
    swap(str[i], str[index]);
    permutationsOfWord(str, index + 1);
    swap(str[index], str[i]);
  }
  return;
}

int main()
{
  permutationsOfWord("ABC", 0);

  return 0;
}
