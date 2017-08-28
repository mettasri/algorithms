#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Person
{
  public:
    string name;
    string email;

    Person(string n, string e) {
      name = n;
      email = e;
    }
};

void groupEmails(Person *p, int size)
{
  int index = 0;
  vector<string> nameList(size, "");
  map<string, int> mapMail;
  map<string, int>::iterator it;

  for(int i = 0; i < size; i++) {
    string email = p[i].email.substr(0, p[i].email.find("@"));
    it = mapMail.find(email);
    if(it != mapMail.end()) {
      nameList[it->second] = nameList[it->second] + "," +  p[i].name;
    } else {
      mapMail.insert(pair<string, int>(email, index));
      nameList[index] = p[i].name;
      index++;
    }
  }
  for(int i = 0; i < index; i++) {
    cout << "{" << nameList[i] << "}" << endl;
  }
}

int main()
{
  Person p[] = {Person("C1", "scott@gmail.com"), 
                Person("C2", "eric@hotmail.com"), 
                Person("C3", "scott@gmail.com"), 
                Person("C4", "scott@microsoft.com"), 
                Person("C5", "eric@gmail.com"), 
                Person("C6", "sam@mail.com"), 
                Person("C7", "scott@gmail.com")};

  int size = sizeof(p)/sizeof(p[0]);
  for(int i = 0; i < size; i++) {
    cout << p[i].name << " " << p[i].email << endl;
  }
  cout << endl;

  groupEmails(p, size);
}
