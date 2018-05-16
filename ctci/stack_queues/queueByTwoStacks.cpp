#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    MyQueue() {}

    void enQueue(int data)  {
      s1.push(data);
    }

    int deQueue() {
      if(s2.empty())  {
        moveDataFromS1toS2();
      }
      if(! (s2.empty()))  {
        int data = s2.top();
        s2.pop();
        return data;
      } else {
        cout << "Queue Empty " << endl;
        return (-1);
      }
    }

    void moveDataFromS1toS2()  {
      while(! (s1.empty())) {
        s2.push(s1.top());
        s1.pop();
      }
    }
};

int main()
{
  MyQueue q;

  q.enQueue(10);
  q.enQueue(20);
  q.enQueue(30);
  q.enQueue(40);
  q.enQueue(50);
  q.enQueue(60);

  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
}
