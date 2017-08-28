#include <iostream>
#include <iomanip>
using namespace std;

#define STACK_SIZE 5
#define NUM_STACKS  2

struct Stack {
  int top[NUM_STACKS];
  int array[NUM_STACKS * STACK_SIZE];
};

void stackInit(Stack &st)
{
  st.top[0] = -1;
  st.top[1] = NUM_STACKS * STACK_SIZE;
}

void push(Stack &st, int stId, int val)
{
  if(st.top[0] + 1 == st.top[1]) {
    cout << "Stack Full" << endl;
    return;
  }

  int &t = st.top[stId];
  if(stId == 0) {
    st.array[++t] = val;
  } else {
    st.array[--t] = val;
  }
}

int pop(Stack &st, int stId)
{
  int &t = st.top[stId];
  if(stId == 0) {
    if(t == -1) {
      cout << "Stack Empty for stId: " << stId << endl;
      return (-1);
    }
    return st.array[t--];
  } else {
    if(st.top[stId] == NUM_STACKS * STACK_SIZE) {
      cout << "Stack Empty for stId: " << stId << endl;
      return (-1);
    }
    return st.array[t++];
  }
}


int main()
{
  int i, s1, s2;
  Stack st;
  stackInit(st);

  s1 = 4, s2 = NUM_STACKS * STACK_SIZE - s1;
  for (i = 0; i < s1; i++)
    push(st, 0, (i+1)*10);
  for (i = 0; i < s2; i++)
    push(st, 1, (i+1)*10);

  cout << "Stack 1 => ";
  for (i = 0; i < s1; i++)
    cout << setw(3) << pop(st, 0);
  cout << endl;
  cout << "Stack 2 => ";
  for (i = 0; i < s2; i++)
    cout << setw(3) << pop(st, 1);
  cout << endl;

  return 0;
}
