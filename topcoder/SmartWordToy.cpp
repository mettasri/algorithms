#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

class SmartWordToy {
public:
  string decode(int pos) {
    string str(4, 'a');

    for(int i = 0; i < 4; ++i) {
      str[i] = str[i] + pos % 26;
      pos -= (pos % 26);
      pos /= 26;
    }
    return str;
  }
  int encode(string str) {
    return (26 * 26 * 26 * (str[3] - 'a')) + 
           (26 * 26 * (str[2] - 'a')) + 
           (26 * (str[1] - 'a')) + (str[0] - 'a');
  }

  void updateForbid(int ind, vector<string> const &str, 
                    string &res, int len, int *dist) {
    if(len == 4) {
      dist[encode(res)] = -1;
      return;
    }

    for(int i = 0; i < str[ind].size(); i++) {
      res[len] = str[ind][i];
      updateForbid(ind + 1, str, res, len + 1, dist);
    }
  }

  int minPresses(string const &start,
                 string const &finish,
                 vector<string> const &forbid) {
    int size = encode("zzzz");
    int *queue = new int[1 + size];
    int *dist  = new int[1 + size];
    for(int i = 0; i < (1 + size); ++i)
      dist[i] = 0;

    for(auto raw_str : forbid) {
      string res(4, 'a');
      vector<string> str;
      stringstream ss(raw_str);
      copy(istream_iterator<string>(ss), istream_iterator<string>(),
           back_inserter(str));
      updateForbid(0, str, res, 0, dist);
    }

    int pos, npos;
    int target = encode(finish);
    int head = 0, tail = 0;

    dist[encode(start)] = 1;
    queue[head++] = encode(start);

    while(tail < head) {
      pos = queue[tail++];

      if(pos == target) {
        return dist[target] - 1;
      }

      string word = decode(pos);
      for(int delta = -1; delta <= 1; delta +=2) {
        for(int i = 0; i < 4; ++i) {
          string nword = word;
          nword[i] += delta;
          if(nword[i] < 'a') nword[i] = 'z';
          else if(nword[i] > 'z') nword[i] = 'a';
          
          npos = encode(nword);
          if(dist[npos] == 0) {
            queue[head++] = npos;
            dist[npos] = dist[pos] + 1;
//            cout << word << " " << nword << endl;
          }
        }
      }
    }
    delete[] queue;
    delete[] dist;

    return -1;
  }
};
