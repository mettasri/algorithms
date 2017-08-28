// A recursive program to test whether a given string can be segmented into
// space separated words in dictionary
#include <iostream>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
   An array of strings is used for dictionary.  Using array of strings for
   dictionary is definitely not a good idea. We have used for simplicity of
   the program*/
int dictionaryContains(string word)
{
  string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
    "icecream","and","go","i","like","ice","cream"};
  int size = sizeof(dictionary)/sizeof(dictionary[0]);
  for (int i = 0; i < size; i++)
    if (dictionary[i].compare(word) == 0)
      return true;
  return false;
}

// returns true if string can be segmented into space separated
// words, otherwise returns false
void wordBreak(string str, string res)
{
  int size = str.size();
  if(0 == size) {
    cout << res << endl;
    return;
  }

  // Try all prefixes of lengths from 1 to size
  for (int i=1; i<=size; i++) {
    string prefix = str.substr(0, i);
    if (dictionaryContains(prefix)) {
      wordBreak(str.substr(i, size-i), res + prefix + " ");
    }
  }
}

// Driver program to test above functions
int main()
{
  wordBreak("ilikesamsung", "");
  wordBreak("iiiiiiii", "");
  wordBreak("", "");
  wordBreak("ilikelikeimangoiii", "");
  wordBreak("samsungandmango", "");
  wordBreak("samsungandmangok", "");

  return 0;
}

