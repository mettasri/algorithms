#include <iostream>
#include <stack>
using namespace std;

class Tower
{
  private:
    char index;
    stack<int> disks;

  public:
    Tower() {}
    void set(char i) {
      index = i;
    }
    void push(int disk) {
      if(! disks.empty() && disk >= disks.top())  {
        cout << "Error: insert disk is larger than top dics" << endl;
        return;
      }
      disks.push(disk);
    }
    int pop() {
      int disk = disks.top();
      disks.pop();
      return disk;
    }
    void moveDisks(int n, Tower &dstTwr, Tower &auxTwr)  {
      if(n > 0) {
        moveDisks(n - 1, auxTwr, dstTwr);
        moveTopTo(dstTwr);
        auxTwr.moveDisks(n - 1, dstTwr, *this);
      }
    }
    void moveTopTo(Tower &twr)  {
      int disk = this->pop();
      cout << "move disk " << disk << " from " << index << " to " << twr.index << endl;
      twr.push(disk);
    }
};

class TowersOfHanoi
{
  private:
    int numDisks;
    Tower srcTwr;
    Tower dstTwr;
    Tower auxTwr;

  public:
    TowersOfHanoi(int numDisks) : numDisks(numDisks) {
      srcTwr.set('A');
      auxTwr.set('B');
      dstTwr.set('C');
      for(int i = numDisks; i > 0; --i) {
        srcTwr.push(i);
      }
    }
    void moveFromSrcToDst()  {
      srcTwr.moveDisks(numDisks, dstTwr, auxTwr);
    }
};

int main()
{
  TowersOfHanoi th(4);
  th.moveFromSrcToDst();
}
