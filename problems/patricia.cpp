#include <iostream>
using namespace std;

/** Class PatriciaNode **/
class PatriciaNode
{
  public:
    int bitNumber;
    int data;
    class PatriciaNode *leftChild, *rightChild;
};

/* Class PatriciaTrie */
class PatriciaTrie
{
  public:
    PatriciaNode *root;
    int MaxBits;

    /** Constructor **/
    PatriciaTrie()
    {
      MaxBits = 10;
      root = NULL;        
    }
    /** function to check if empty **/
    bool isEmpty()
    {
      return root == NULL;
    }
    /** function to clear **/
    void makeEmpty()
    {
      root = NULL;        
    }
    /** function to get ith bit of key k from left **/
    bool bit(int k, int i)
    {
      if(k & 1 << (i - 1))
        return true;
      else
        return false;
//      String binary = Integer.toString(k, 2);    
//      while (binary.length() != MaxBits)
//        binary = "0" + binary;    
//      if (binary.charAt(i - 1) == '1')
//        return true ;
//      return false;
    }
    /** function to search for an element **/
    bool search(int k)
    {
//      int numOfBits = (int) (Math.log(k)/Math.log(2)) + 1;
      int numOfBits = 8;
      if (numOfBits > MaxBits)
      {
        cout << "Error : Number too large" << endl;
        return false;
      }
      PatriciaNode *searchNode = search(root, k);
      if (searchNode->data == k)
        return true;
      else
        return false;
    }
    /** function to search for an element **/
    PatriciaNode* search(PatriciaNode *t, int k)
    {
      PatriciaNode *currentNode, *nextNode;
      if (t == NULL)
      {
        return NULL;
      }
      nextNode = t->leftChild;
      currentNode = t;
      while (nextNode->bitNumber > currentNode->bitNumber)
      {
        currentNode = nextNode;
        nextNode = (bit(k, nextNode->bitNumber)) ? nextNode->rightChild : nextNode->leftChild;
      }
      return nextNode;
    }
    /** function to insert and element **/
    void insert(int ele)
    {
      int numOfBits = 8;
      if (numOfBits > MaxBits)
      {
        cout << "Error : Number too large" << endl;
        return;
      }
      root = insert(root, ele);        
    }
    /** function to insert and element **/
    PatriciaNode* insert(PatriciaNode* t, int ele)
    {
      PatriciaNode *current, *parent, *lastNode, *newNode;
      int i;
      cout << "new ele: " << ele << endl;

      if (t == NULL)
      {
        t = new PatriciaNode();
        t->bitNumber = 0;
        t->data = ele;
        t->leftChild = t;
        t->rightChild = NULL;    

//        cout << t << endl;
//        cout << t->bitNumber << endl;
//        cout << t->data << endl;
//        cout << t->leftChild << endl;
//        cout << t->rightChild << endl << endl;

        return t;        
      }

      lastNode = search(t, ele);

      if (ele == lastNode->data)
      {
        cout << "Error : key is already present" << endl;
        return t;
      }

      for (i = 1; bit(ele, i) == bit(lastNode->data, i); i++);

      cout << "i: " << i << endl;

      current = t->leftChild; parent = t;
      while (current->bitNumber > parent->bitNumber && current->bitNumber < i)
      {
        parent = current;
        current = (bit(ele, current->bitNumber)) ? current->rightChild : current->leftChild;
      }


      newNode = new PatriciaNode();
      newNode->bitNumber = i;
      newNode->data = ele;
      newNode->leftChild = bit(ele, i) ? current : newNode;
      newNode->rightChild = bit(ele, i) ? newNode : current;        

      if (current == parent->leftChild)
      {
        parent->leftChild = newNode;
        cout << "parent: (" << parent << ", data: " << parent->data << ", bit: " << parent->bitNumber << ")";
        cout << " Left-> (" << newNode << " data: " << newNode->data << ", bit: " << newNode->bitNumber << ")" << endl;
      }
      else
      {
        parent->rightChild = newNode;
        cout << "parent: (" << parent << ", data: " << parent->data << ", bit: " << parent->bitNumber << ")";
        cout << " Right-> (" << newNode << " data: " << newNode->data << ", bit: " << newNode->bitNumber << ")" << endl;
      }

//        cout << newNode << endl;
//        cout << newNode->bitNumber << endl;
//        cout << newNode->data << endl;
//        cout << newNode->leftChild << endl;
//        cout << newNode->rightChild << endl << endl;
//
//        cout << newNode->leftChild->leftChild << endl;
//        cout << newNode->leftChild->rightChild << endl;
//
//        cout << newNode->rightChild->leftChild << endl;
//        cout << newNode->rightChild->rightChild << endl;

      return t;
    }        
};

int main()
{
  /* Creating object of PatriciaTrie */
  PatriciaTrie *pt = new PatriciaTrie(); 

  int ch;
  int val;
  /*  Perform trie operations  */
  while(1)
  {
    cout << "Patricia Trie Operations" << endl;
    cout << "1. insert " << endl;
    cout << "2. search" << endl;
    cout << "3. check empty" << endl;
    cout << "4. make empty" << endl;
    cin >> ch;

    cout << ch << endl;

    switch (ch)
    {
      case 1 : 
        cout <<"Enter key element to insert: ";
        cin >> val;
        pt->insert(val);                     
        break;                          
      case 2 : 
        cout <<"Enter key element to search" << endl;
        cin >> val;
        cout <<"Search result : " << pt->search(val) << endl;
        break;  
      case 3 : 
        cout <<"Empty Status : " << pt->isEmpty() << endl;
        break;    
      case 4 : 
        cout <<"Patricia Trie cleared" << endl;
        pt->makeEmpty();               
        break;                                        
      default : 
        cout <<"Wrong Entry" << endl;
        break;   
    }
  }
}
