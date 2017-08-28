#include <iostream>
using namespace std;

int add(int a, int b) {
  int carry;

  while(b) {
    carry = a & b;
    a = a ^ b;  // addition
    b = carry << 1; // carry
  }
  return a;
}

int main() {
  int a, b;

  while(true) {
    cin >> a >> b;
    cout << "sum: " << add(a, b) << endl;
  }
}
