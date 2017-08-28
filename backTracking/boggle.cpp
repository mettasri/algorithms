#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);

int isWord(string str)
{
  for(int i = 0; i < n; i++)
    if(dictionary[i].compare(str) == 0)
      return true;
  return false;
}

int xCord[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int yCord[] = {-1,  0,  1, 1, 1, 0,-1,-1};

void boggle(vector<vector<char> >& boggleVector, vector<vector<bool> >& visited, 
    vector<string>& words, string str, int i, int j)
{
  if(isWord(str)) {
    words.push_back(str);
  }

  for(int k = 0; k < 8; k++) {
    int x = i + xCord[k];
    int y = j + yCord[k];
    if(x >= 0 && x < 3 && y >= 0 && y < 3 && !visited[x][y]) {
      visited[i][j] = true;
      boggle(boggleVector, visited, words, str + boggleVector[x][y], x, y);
      visited[i][j] = false;
    }
  }
}

int main()
{
  const char boggleArray[][3] = {{'G','I','Z'},
                                 {'U','E','K'},
                                 {'Q','S','E'}};

  vector<vector<bool> > visited(3, vector<bool>(3, false));
  vector<vector<char> > boggleVector;
  
  for(int i = 0; i < 3; i++)  {
    boggleVector.push_back(vector<char>());
    for(int j = 0; j < 3; j++)  {
      boggleVector[i].push_back(boggleArray[i][j]);
    }
  }
/*  
  vector<vector<bool> >::iterator it1;
  vector<bool>::iterator it2;
  for(it1 = v.begin(); it1 != v.end(); ++it1) {
    for(it2 = it1->begin(); it2 != it1->end(); ++it2) {
      cout << *it2 << " ";
    }
    cout << endl;
  }
*/
  vector<string> words;
  string str = "";

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      boggle(boggleVector, visited, words, str + boggleVector[i][j], i, j);

  for(int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }

  return 0;
}
