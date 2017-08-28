/* Numbers ending in 3 have at least one multiple having all ones.
 * for eg., 3 and 13 have amultiples like 111 and 111111 respectively. 
 * Given such a no. , find the smallest such multiple of that number. 
 * The multiple can exceed the range of int, long. You cannot use any 
 * complex data structure.
 */
#include <iostream>
using namespace std;

void numEndingThreeMultipleOfOnes(int num)
{
  int count = 1, rem = 1;

  while(rem) {
    rem = (rem * 10 + 1) % num;
    count++;
  }
  while(count--) {
    cout << '1';
  }
  cout << endl;
}

int main()
{
  int num;
  while(true) {
    cout << "Enter num: "; cin >> num;
    numEndingThreeMultipleOfOnes(num);
  }
  
  return 0;
}
