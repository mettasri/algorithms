#include <iostream>
#include <list>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define ARRAY_SIZE 256
typedef struct TRIE
{
  int isLeafNode;
  int strIndex;
  string str;
  struct TRIE *children[ARRAY_SIZE];
} Trie;

Trie* getNode()
{
  Trie *node = new Trie();

  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    node->children[i] = NULL;
  }
  node->isLeafNode = 0;

  return node;
}

int prefix(string str, int strIndex, string key, int index)
{
  for(int i = 0; i < str.length(); i++)
    if(strIndex == index || str[i] != key[i])
      return strIndex;
  return str.length();
}

Trie* insertWord(Trie *pRoot, string key, int index)
{
  if(! key.length())  return NULL;

  if(! pRoot) {
    pRoot = getNode();
    pRoot->str = key;
    pRoot->isLeafNode = 1;
    pRoot->strIndex = index;

    return pRoot;
  }
  // find the prefix match string
  int i = prefix(pRoot->str, pRoot->strIndex, key, index);
  pRoot->children[key.at(index + 1)] = insertWord(pRoot->children[key.at(index + 1)], key, index + i);

  pRoot->children[key.at(index + 1)] = insertWord(pRoot->children[key.at(index + 1)], key, index + 1);
  return pRoot->children[key.at(index + 1)];
}

/*
void insertWord(Trie *pRoot, string key)
  Trie *pCrawl = pRoot;

  for(int i = 0; i < key.length(); i++)
  {
    if(! pCrawl->children[key.at(i)])
      pCrawl->children[key.at(i)] = getNode();
    pCrawl = pCrawl->children[key.at(i)];
  }
  pCrawl->isLeafNode = 1;
*/

int isItFreeNode(Trie *pRoot)
{
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    if(pRoot->children[i])
      return 0;
  }
  return 1;
}

int removeWord(Trie *pRoot, string key)
{
  if(! pRoot) return 0;

  if(! key.length())  {
    if(pRoot->isLeafNode)
    {
      pRoot->isLeafNode = 0;
      if(isItFreeNode(pRoot))
        return 1;
      else
        return 0;
    }
  }

  if(removeWord(pRoot->children[key.at(0)], key.substr(1)))
  {
    cout << key.at(0) << " deleted" << endl;
    delete(pRoot->children[key.at(0)]);
    pRoot->children[key.at(0)] = NULL;

    if(! pRoot->isLeafNode && isItFreeNode(pRoot))
      return 1;
  }
  return 0;
}

int search(Trie *pRoot, string key)
{
  if(! pRoot) return 0;
  
  if(! key.length())
  {
    if(pRoot->isLeafNode) 
      return 1;
    else
      return 0;
  }

  return search(pRoot->children[key.at(0)], key.substr(1));
}

void displayTrie(Trie *pRoot, string str)
{
  if(!pRoot)  return;
  if(pRoot->isLeafNode)
  {
    cout << str << endl;
    return;
  }

  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    if(pRoot->children[i])
      displayTrie(pRoot->children[i], str + "|" + char(i));
  }
}

int main()
{
  // Input keys (use only 'a' through 'z' and lower case)
  string keys[7] = {"romane", "romanus", "romulus", "rubens", "ruber", "rubicon", "rubicundus"};
  string output[2] = {"Not present in trie", "Present in trie"};

  Trie *root = getNode();

  // Construct trie
  for (int i = 0; i < 7; i++)
    root->children[key[i].substr(0)] = insertWord(root->children[key[i].substr(0)], keys[i], 0);

  string str = "";
  displayTrie(root, str);

  // Search for different keys
//  cout << "romane    : " << output[search(root, "romane")] << endl;;
//  cout << "romanus   : " << output[search(root, "romanus")] << endl;
//  cout << "romulus   : " << output[search(root, "romulus")] << endl;
//  cout << "rubens    : " << output[search(root, "rubens")] << endl;
//  cout << "ruber     : " << output[search(root, "ruber")] << endl;
//  cout << "rubicon   : " << output[search(root, "rubicon")] << endl;
//  cout << "rubicundus: " << output[search(root, "rubicundus")] << endl;

  return 0;
}
