// A Dynamic Programming based program to test whether a given string can
// be segmented into space separated words in dictionary
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
   An array of strings is used for dictionary.  Using array of strings for
   dictionary is definitely not a good idea. We have used for simplicity of
   the program*/
int dictionaryContains(string word)
{
  string dictionary[] = {"mobile","samsung","sam","sun", "man","mango",
    "icecream","and","go","i","like","ice","cream"};
  int size = sizeof(dictionary)/sizeof(dictionary[0]);
  for (int i = 0; i < size; i++)
    if (dictionary[i].compare(word) == 0)
      return true;
  return false;
}

void printDp(int wb[], int size)
{
  /* Uncomment these lines to print DP table "wb[]"*/
  for (int i = 1; i <= size; i++)
    cout << setfill(' ') << setw(2) << wb[i];
  cout << endl;
}
void printString(string str)
{
  for (int i = 0; i < str.length(); i++)
    cout << setfill(' ') << setw(2) << str.at(i);
  cout << endl;
}
// Returns true if string can be segmented into space separated
// words, otherwise returns false
bool wordBreakDp(string str)
{
  int size = str.size();
  if (size == 0)   return true;

  printString(str);

  int wb[size+1];
  memset(wb, 0, sizeof(wb)); // Initialize all values as false.

  for (int i=1; i<=size; i++)
  {
    if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
    {
      wb[i] = 1;
    }
    if (wb[i] != false)
    {
//      if (i == size)
//        return true;

      for (int j = i+1; j <= size; j++)
      {
        if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
        {
          wb[j] = 2;
        }
        // If we reached the last character
//        if (j == size && wb[j] != false)
//        {
//          printDp(wb, size);
//          return true;
//        }
      }
    }
    printDp(wb, size);
  }
//  printDp(wb, size);
  return wb[size];
//  return false;
}

// Driver program to test above functions
int main()
{
  false != wordBreakDp("ilikeicecreamandmango")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("ilikesamsung")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("iiiiiiii")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("ilikelikeimangoiii")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("samsungandmango")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDp("samsungandmangok")? cout <<"FAIL\n": cout << "PASS\n";
//  false != wordBreakDp("ilikeicecream")? cout <<"PASS\n": cout << "FAIL\n";

//  false != wordBreakDpRec("ilikesamsung")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDpRec("iiiiiiii")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDpRec("")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDpRec("ilikelikeimangoiii")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDpRec("samsungandmango")? cout <<"PASS\n": cout << "FAIL\n";
//  false != wordBreakDpRec("samsungandmangok")? cout <<"FAIL\n": cout << "PASS\n";
//  false != wordBreakDpRec("ilikeicecream")? cout <<"PASS\n": cout << "FAIL\n";
  return 0;
}

