#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

#define MAX_CHAR 256

class Trie
{
  Trie *children[MAX_CHAR];
  list<int> *indexList;

  public:
    Trie()  {
      indexList = new list<int>;

      for(int i = 0; i < MAX_CHAR; i++)
        children[i] = NULL;
    }

    void createTrie(string suf, int index, char ch) {
//      cout << index << " " << suf << endl;
      indexList->push_back(index);
      
      if(! suf.length())  {
        return;
      }
      if(! children[suf[0]])  {
        children[suf[0]] = new Trie();
      }
//      cout << ch << " list: " << indexList->size() << endl;
      children[suf[0]]->createTrie(suf.substr(1), index + 1, suf[0]);
    }

    list<int> *searchSuffix(string suf) {
      if(!suf.length())
        return indexList;
      if(children[suf[0]])
        return children[suf[0]]->searchSuffix(suf.substr(1));
      else
        return NULL;
    }
    
    void displayTri(char ch) {
      for(list<int>::iterator it = indexList->begin(); it != indexList->end(); it++)
        cout << *it << " ";
      cout << endl;

//      cout << ch << " list: " << indexList->size() << endl;
      for(int i = 0; i < MAX_CHAR; i++) {
        if(children[i]) {
          children[i]->displayTri(i);
        }
      }
    }
};

class SuffixTrie
{
  Trie root;

  public:
    SuffixTrie()  {
    }

    void createSuffixTrie(string text) {
      for(int i = 0; i < text.length(); i++)  {
//        cout << i << "  " << text.substr(i) << endl;
        root.createTrie(text.substr(i), i, '@');
//        cout << endl;
      }
    }
    void searchSuffixTrie(string suf) {
      list<int> *sufList = root.searchSuffix(suf);

      if(!sufList)  {
        cout << suf << ": not found" << endl;
        return;
      }
      
      for(list<int>::iterator it = sufList->begin(); it != sufList->end(); it++)
        cout << suf << ": found @ "<< *it - suf.length() << endl;
    }
    void displaySuffixTrie()  {
      cout << "Trie contents... " << endl;
      root.displayTri('@');
    }
};

int main()
{
  string text = "geeksforgeeks.org";
  SuffixTrie sufTrie;

  for(int i = 0; i < text.length(); i++)
  {
    cout << setw(3) << i;
  }
  cout << endl;
  for(int i = 0; i < text.length(); i++)
  {
    cout << setw(3) << text[i];
  }
  cout << endl;

  sufTrie.createSuffixTrie(text);
//  sufTrie.displaySuffixTrie();

  sufTrie.searchSuffixTrie("geek");
  sufTrie.searchSuffixTrie("ee");
  sufTrie.searchSuffixTrie("quiz");
  sufTrie.searchSuffixTrie("forgeeks");

}
