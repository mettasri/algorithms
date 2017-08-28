#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

#define ARRAY_SIZE 256
typedef struct Ternary_Search_Tree
{
  unsigned char ch;
  int isStringEnd;
  struct Ternary_Search_Tree *pLeft;
  struct Ternary_Search_Tree *pEqual;
  struct Ternary_Search_Tree *pRight;
} Tst;

Tst* getNewNode(unsigned char val)
{
  Tst *pNewNode = new Tst();

  pNewNode->isStringEnd = 0;
  pNewNode->ch = val;
  pNewNode->pLeft  = NULL;
  pNewNode->pEqual = NULL;
  pNewNode->pRight = NULL;

  return pNewNode;
}

void insertWord(Tst **pRoot, string str)
{
  if(! *pRoot) {
    *pRoot = getNewNode(str.at(0));
  }
  if(str.at(0) < (*pRoot)->ch) {
    insertWord(&((*pRoot)->pLeft), str);
  }
  else if(str.at(0) > (*pRoot)->ch) {
    insertWord(&((*pRoot)->pRight), str);
  }
  else
  {
    if(str.length() > 1)
      insertWord(&((*pRoot)->pEqual), str.substr(1));
    else
      (*pRoot)->isStringEnd = 1;
  }
}

void traverseTst(Tst *pRoot, string str)
{
  if(!pRoot) return;

  string str1 = str;
  str1 += pRoot->ch;

  traverseTst(pRoot->pLeft, str);
  
  if(pRoot->isStringEnd)
    cout << str1 << endl;
  traverseTst(pRoot->pEqual, str1);
  
  traverseTst(pRoot->pRight, str);
}

int search(Tst *pRoot, string str)
{
  if(! pRoot)  return 0;

  if(str.at(0) < pRoot->ch)
    return search(pRoot->pLeft, str);
  else if(str.at(0) > pRoot->ch)
    return search(pRoot->pRight, str);
  else
  {
    if(str.length() == 1 && pRoot->isStringEnd)
      return 1;
    return search(pRoot->pEqual, str.substr(1));
  }
}

int main()
{
  // Input keys (use only 'a' through 'z' and lower case)
  string keys[12] = {"as", "at", "be", "by", "he", "in", "is", "it", "of", "on", "or", "to"};
  string output[2] = {"Not present in trie", "Present in trie"};
  
  Tst *pRoot = NULL;

  // Construct trie
  for (int i = 0; i < 12; i++)
    insertWord(&pRoot, keys[i]);

  string str = "";
  traverseTst(pRoot, str);
  // Search for different keys
  for (int i = 0; i < 12; i++)
    cout << keys[i] << ": " << output[search(pRoot, keys[i])] << endl;

  cout << "st: " << output[search(pRoot, "st")] << endl;
  cout << "ey: " << output[search(pRoot, "ey")] << endl;
  cout << "bey: " << output[search(pRoot, "bey")] << endl;

  return 0;
}
