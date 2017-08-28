// C++ program to print pattern that first reduces 5 one 
// by one, then adds 5. Without any loop an extra variable.
#include <iostream>
using namespace std;

void printPattern(int n)
{
  if(n < 0) {
    cout << n << " ";
    return;
  }

  cout << n << " ";
  printPattern(n-5);
  cout << n << " ";
}

// Driver Program
int main()
{
  int n = 16;
  printPattern(n);
  return 0;
}
