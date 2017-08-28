#include <iostream>
using namespace std;

class Node {
 public:
  int eleSize;
  void *ele;
  Node *pNext;

  Node()  {
    ele = NULL;
    pNext = NULL;
  }
};

class stack {
  Node *pTop;
  int count;
  int maxSize;

 public:
  stack(int size) {
    count = 0;
    maxSize = size;
    pTop = NULL;
  }
  bool isEmpty() const { return pTop == NULL; }
  bool isFull()  const { return count == maxSize; }

  void push(void *val, int size) {
    if(isFull())  {
      cout << "Stack full" << endl;
      return;
    }

    Node *pTemp = new Node();
    memcpy(pTemp->ele, val, size);
    pTemp->pNext = pTop;
    pTop = pTemp;
    count++;
  }
  
  Node* top() {
    if(! isEmpty())  {
      return pTop;
    }
  }
  
  void pop() {
    if(isEmpty())  {
      cout << "Stack is empty" << endl;
      return;
    }
    Node *pTemp = pTop;
    int val = pTemp->data;
    pTop = pTop->pNext;
    delete pTemp;

    return val;
  }
};

int main() {
  stack st(5);
  int x;

  x = 10; st.push((void *)&x, sizeof(int));
  x = 20; st.push((void *)&x, sizeof(int));
  x = 30; st.push((void *)&x, sizeof(int));
  x = 40; st.push((void *)&x, sizeof(int));
  x = 50; st.push((void *)&x, sizeof(int));
  x = 60; st.push((void *)&x, sizeof(int));

  cout << "Stack contents: " << endl;
  cout << st.pop();
  cout << st.pop();
  cout << st.pop();
  cout << st.pop();
  cout << st.pop();
  cout << st.pop();
}
