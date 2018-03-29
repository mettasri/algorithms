#include <iostream>
using namespace std;
/**
 *                    ABC
 *         -------------------------
 *         |           |           |
 *        ABC         BAC         CBA
 *       /   \       /   \       /   \
 *     ABC   ACB   BAC   BCA   CBA   CAB
 */
void permutation(string str, int index) {
  if(index == str.size()) {
    cout << str << endl;
    return;
  }

  for(int i = index; i < str.size(); i++) {
    swap(str[index], str[i]);
    permutation(str, index + 1);
    swap(str[index], str[i]);
  }
  return;
}

/**
 *                      ABC/
 *         ---------------------------
 *         |             |           |
 *        BC/A         AC/B         AB/C
 *       /    \       /    \       /    \
 *     C/AB   B/AC  C/BA  A/BC   B/CA   A/CB
 *     /      /     /     /      /      /
 *   ABC    ACB   BAC   BCA    CAB    CBA                  // n! leaves
 */

void permutation(string str, string res) {
  if (str.length() == 0) {
    cout << res << endl;  // O(n)
    return;
  }

  for (int i = 0; i < str.length(); ++i) {  // n!
    string rem = str.substr(0, i) + str.substr(i + 1);  // n * n!
    permutation(rem, res + str[i]);
  }
}

int main()
{
  cout << "Method #1" << endl;
  permutation("ABC", 0);
  cout << endl << "Method #2" << endl;
  permutation("ABC", "");

  return 0;
}
