#include <iostream>
#include <iomanip>
using namespace std;
#define STACKSIZE 3

class StackData
{
  public:
    int indexNext;
    int data;

    StackData() { }
    StackData(int next, int val) : indexNext(next), data(val) { }

};
class kStacksFromAnArray
{
  private:
    int numStacks;
    int totalSize;
    int freeIndex;
    int *stackPointers;
    StackData *sData;

  public:
    kStacksFromAnArray(int k, int size)  {
      numStacks = k;
      totalSize = k * size;
      stackPointers = new int[numStacks];
      sData = new StackData[totalSize];

      freeIndex = 0;
      for(int i = 0; i < totalSize; i++)  {
        sData[i].indexNext = i + 1;
      }
      sData[totalSize - 1].indexNext = -1;

      for(int i = 0; i < numStacks; i++)  {
        stackPointers[i] = -1;
      }
    }

    void displayIndexNext() {
      cout << setw(3) << freeIndex << endl;
      for(int i = 0; i < totalSize; i++)  {
        cout << setw(3) << sData[i].indexNext;
      }
      cout << endl;

      for(int i = 0; i < numStacks; i++)  {
        cout << setw(3) << stackPointers[i];
      }
      cout << endl << endl;
    }

    void push(int stackNum, int val) {
      if(freeIndex == -1)  {
        cout << "Array Full" << endl;
        return;
      }
      sData[freeIndex].data = val;
      int free = sData[freeIndex].indexNext;
      sData[freeIndex].indexNext = stackPointers[stackNum];
      stackPointers[stackNum] = freeIndex;
      freeIndex = free;
      displayIndexNext();
    }

    int pop(int stackNum) {
      if(stackPointers[stackNum] == -1)  {
        cout << "Stack Empty" << endl;
        return (-1);
      }
      int top = stackPointers[stackNum];
      stackPointers[stackNum] = sData[top].indexNext;
      sData[top].indexNext = freeIndex;
      freeIndex = top;
      cout << "data: " << sData[top].data << endl;
      displayIndexNext();
      return sData[top].data;
    }
};

int main()
{
  kStacksFromAnArray kS(3, STACKSIZE);

  kS.push(0, 10);
  kS.push(0, 20);
  kS.push(0, 30);

  kS.push(1, 40);
  kS.push(1, 50);
  kS.push(1, 60);

  kS.push(2, 70);
  kS.push(2, 80);
  kS.push(2, 90);

  kS.pop(2);
  kS.pop(2);
  kS.pop(2);

  kS.pop(1);
  kS.pop(1);
  kS.pop(1);

  kS.pop(0);
  kS.pop(0);
  kS.pop(0);
}
