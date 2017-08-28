#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

#define ARRAY_SIZE 256
typedef struct TRIE
{
  struct TRIE *children[ARRAY_SIZE];
  int isLeafNode;
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

void insertWord(Trie *pRoot, string key)
{
/*  
  if(! key.length())
  {
    pRoot->isLeafNode = 1;
    return;
  }

  if(! pRoot->children[key.at(0)])
    pRoot->children[key.at(0)] = getNode();

  insertWord(pRoot->children[key.at(0)], key.substr(1));
*/
  Trie *pCrawl = pRoot;

  for(int i = 0; i < key.length(); i++)
  {
    if(! pCrawl->children[key.at(i)])
      pCrawl->children[key.at(i)] = getNode();
    pCrawl = pCrawl->children[key.at(i)];
  }
  pCrawl->isLeafNode = 1;
}

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

int main()
{
  // Input keys (use only 'a' through 'z' and lower case)
  string keys[8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  string output[2] = {"Not present in trie", "Present in trie"};

  Trie *root = getNode();

  // Construct trie
  for (int i = 0; i < 8; i++)
    insertWord(root, keys[i]);

  // Search for different keys
  cout << "the   : " << output[search(root, "the")] << endl;;
  cout << "these : " << output[search(root, "these")] << endl;
  cout << "there : " << output[search(root, "there")] << endl;
  cout << "their : " << output[search(root, "their")] << endl;
  cout << "thaw  : " << output[search(root, "thaw")] << endl;

  removeWord(root, "there");
  cout << "there : " << output[search(root, "there")] << endl;

  removeWord(root, "their");
  cout << "their : " << output[search(root, "their")] << endl;

  removeWord(root, "the");
  cout << "the : " << output[search(root, "the")] << endl;

  removeWord(root, "answer");
  cout << "answer : " << output[search(root, "answer")] << endl;

  return 0;
}
