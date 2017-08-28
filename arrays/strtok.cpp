#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  char myText[] = "some-text-to-tokenize";
  istringstream iss(myText);
  string token;

  while (getline(iss, token, '-')) {
    cout << token << std::endl;
  }
}
