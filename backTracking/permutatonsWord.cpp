#include <iostream>
using namespace std;
/**
 *                    ABC
 *         -------------------------
 *         |           |           |
 *        ABC         BAC         CBA       swap(0, {0, 1, 2})
 *       /   \       /   \       /   \
 *     ABC   ACB   BAC   BCA   CBA   CAB    swap(1, {1, 2})
 */
void permutation1(string str, int index) {
  if(index == str.size()) {
    cout << str << endl;
    return;
  }

  for(int i = index; i < str.size(); i++) {
    swap(str[index], str[i]);
    permutation1(str, index + 1);
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

void permutation2(string str, string res) {
  if (str.length() == 0) {
    cout << res << endl;  // O(n)
    return;
  }

  for (int i = 0; i < str.length(); ++i) {  // n!
    string rem = str.substr(0, i) + str.substr(i + 1);  // n * n!
    permutation2(rem, res + str[i]);
  }
}

/**
 *                ABC/
 *                 |            
 *                BC/A 
 *          ---------------
 *          |             |
 *        C/AB           C/BA
 *     -----------     -----------
 *     |    |    |     |    |    |
 *    CAB  ACB  ABC   CBA  BCA  BAC
 */
void permutation3(string str, string res) {
  if (str.length() == 0) {
    cout << res << endl;
    return;
  }

  for (int i = 0; i <= res.length(); ++i) {
    string s = res;
    s.insert(i, 1, str[0]);
    permutation3(str.substr(1), s);
  }
}

int main()
{
  cout << "Method #1\n";
  permutation1("ABC", 0);

  cout << "\nMethod #2\n";
  permutation2("ABC", "");

  cout << "\nMethod #3\n";
  permutation3("ABC", "");

  return 0;
}
