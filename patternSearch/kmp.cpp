#include <iostream>
using namespace std;

void printPreSuf(int *preSuf, int len)
{
  for(int i = 0; i < len; i++)
  {
    cout << preSuf[i] << " ";
  }
  cout << endl;
}

int findSubstring(string text, string pattern)
{
  int *preSuf = new int[pattern.length()];
  
  int i, j;
  preSuf[0] = 0;

  for(i = 1, j = 0; i < pattern.length() && j >= 0; )
  {
    if(pattern[j] == pattern[i])
    {
      preSuf[i] = j + 1;
      j++;
      i++;
    }
    else if(j == 0)
    {
      preSuf[i] = j;
      i++;
    }
    else
    {
      j = preSuf[j - 1];
    }
  }

  printPreSuf(preSuf, pattern.length());

  for(i = 0, j = 0; i < text.length() && j < pattern.length();) {
    if(text[i] == pattern[j]) {
      i++;
      j++;
      cout << "1: " << i << " " << j << endl;
    } else {
      if(j > 0) {
        j = preSuf[j - 1];
        cout << "2: " << i << " " << j << endl;
      } else
        i++;
      cout << "3: " << i << " " << j << endl;
    }
  }
  if(j == pattern.length())
    return 1;
  return 0;
}

int main()
{
  findSubstring("aabaabaacabcabyaabaabaaa", "aabaabaaa") ? cout << "PASS\n" : cout << "FAIL\n";
  findSubstring("abxabcabcaby", "abcabyx") ? cout << "FAIL\n" : cout << "PASS\n";
//  findSubstring("abcaby");
//  findSubstring("acacabacacabacacac");
}
