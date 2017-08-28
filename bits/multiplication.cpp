#include <iostream>
#include <cstdlib>
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

int multi(int a, int b) {
  int res = 0;
  bool isNeg = (a < 0 && b > 0) || (a > 0 && b < 0);
  a = abs(a);
  b = abs(b);

  while(a) {
//    res += (a & 1) ? b : 0;
    res = (a & 1) ? add(res, b) : res;
    a >>= 1;
    b <<= 1;
  }
  return isNeg ? -res : res;
}

int main() {
  int a, b;

  while(true) {
    cin >> a >> b;
    cout << "multi: " << multi(a, b) << endl;
  }
}
