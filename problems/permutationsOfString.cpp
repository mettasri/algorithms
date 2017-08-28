#include <iostream>
#include <iomanip>
using namespace std;

void permutationsRecursion(string str, int l)
{
  if(l == str.length() - 1) {
    cout << str << endl;
    return;
  }

  for(int i = l; i < str.length(); ++i) {
    swap(str[l], str[i]);
    permutationsRecursion(str, l+1);
    swap(str[l], str[i]);
  }
}

void display(int *perm, int size)
{
  for(int i = 0; i < size; ++i)
    cout << setw(2) << perm[i];
  cout << endl;
}

bool set(int *perm, int size)
{
  int i = size - 2;
  while (++perm[i] >= size) {
    if(0 == i)
      return false;
    i--;
  }
  for(int k = i + 1; k < size; ++k) {
    perm[k] = k;
  }
  return true;
}

void swap(char &c1, char &c2)
{
  char temp = c1;
  c1 = c2;
  c2 = temp;
}

void permutationsIterative(string str)
{
  int size = str.length();
  int *perm = new int[size];
  int i, j;
  string res;

  for(i = 0; i < size; ++i)
    perm[i] = i;

  do {
    res = str;
//    display(perm, size);
    for(i = 0; i < size; ++i) {
      swap(res[i], res[perm[i]]);
    }
    cout << res << endl;
  } while(set(perm, size));
}

int main()
{
//  permutationsRecursion("3210", 0);
  permutationsIterative("A");
}
