#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

class SetOfStacks
{
  private:
    int numSks;
    int skMaxSize;
    int skTop;
    list<int> *skList;

  public:
    SetOfStacks(int noOfSks, int size) : numSks(noOfSks), skMaxSize(size) {
      skTop = 0;
      skList = new list<int>[numSks];
    }

    void push(int val)  {
      if(skTop == numSks * skMaxSize)  {
        cout << "Stack Full" << endl;
        return;
      }
      skList[skTop/skMaxSize].push_front(val);
      skTop++;
    }
    
    int pop() {
      if(skTop == 0)  {
        cout << "Stack Empty" << endl;
        return (-1);
      }
      skTop--;
      int val = skList[skTop/skMaxSize].front();
      skList[skTop/skMaxSize].pop_front();
      return val;
    }

    int popFromAStack(int skIndex) {
      if(skTop == 0)  {
        cout << "All Stacks are Empty" << endl;
        return (-1);
      }
//      cout << "skIndex " << skIndex << " skTop: " << skTop << endl;
      if((skIndex * skMaxSize) >= skTop) {
        cout << "Stack Empty: " << skIndex << endl;
        return (-1);
      }
      int val = skList[skIndex].front();
      skList[skIndex].pop_front();
      int x = slideStacks(skIndex + 1);
      if(x != -1)
        skList[skIndex].push_front(x);
      skTop--;
      return val;
    }

    int slideStacks(int skIndex) {
      if((skIndex * skMaxSize) >= skTop || skList[skIndex].empty())
        return (-1);
      
      int val = slideStacks(skIndex + 1);
      
      if(val != -1) {
        skList[skIndex].push_front(val);
      }
      val = skList[skIndex].back();
      skList[skIndex].pop_back();
      return val;
    }

    void displayStacks()  {
      for(int i = 0; i < numSks; i++) {
        list<int>::iterator it;
        for(it = skList[i].begin(); it != skList[i].end(); it++)  {
          cout << setw(3) << *it;
        }
        cout << endl;
      }
      cout << endl;
    }
};

int main()
{
  int numStacks = 3;
  int stackSize = 5;

  SetOfStacks sk(numStacks, stackSize);

  for(int i = 0; i < numStacks * stackSize; i++)
    sk.push((i+1));

  sk.displayStacks();
//  cout << sk.popFromAStack(0) << endl << endl;
//`  sk.displayStacks();

  for(int i = 0; i < stackSize * numStacks; i++)  {
    cout << sk.popFromAStack(0) << endl << endl;
    sk.displayStacks();
  }
//  for(int i = 0; i < stackSize; i++)  {
//    cout << sk.popFromAStack(2) << endl << endl;
//    sk.displayStacks();
//  }


//  for(int i = 0; i < numStacks * stackSize; i++)
//    cout << "pop val: " << sk.pop() << endl;
}
