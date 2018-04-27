#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Position {
  int x;
  int y;
};

int x_a[] = {0, 1,  0, -1};
int y_a[] = {1, 0, -1,  0};

class WalkingHome {
    int distance[50][50];
    int head, tail;
    Position queue[10000];
public:
  WalkingHome() : head(0), tail(0) {
    resetLookup();
  }

  Position getPosition(char ch, vector<string> const &map) {
    Position pos;
    for(int r = 0; r < map.size(); r++) {
      for(int c = 0; c < map[r].size(); c++) {
        if(ch == map[r][c]) {
          pos.x = r; pos.y = c;
          return pos;
        }
      }
    }
    return pos;
  }

  void resetLookup() {
    for(int r = 0; r < 50; r++) {
      for(int c = 0; c < 50; c++) {
        distance[r][c] = INT_MAX;
      }
    }
  }

  bool isValid(Position &pos, vector<string> const &map) {
    if(pos.x < 0 || pos.x >= map.size() || pos.y < 0 || pos.y >= map[0].size()) {
      return false;
    }
    return true;
  }

  void display(vector<string> const &map) {
    for(auto str : map)
      cout << str << endl;
  }

  void traverseTillEnd(Position cur, vector<string> const &map) {
    Position ncur;
    for(int i = 0; i < 4; i++) {
      ncur.x = cur.x + x_a[i];
      ncur.y = cur.y + y_a[i];

      if(isValid(ncur, map) 
      && distance[ncur.x][ncur.y] > distance[cur.x][cur.y]) {
        if(map[ncur.x][ncur.y] == 'F' || map[ncur.x][ncur.y] == '*')
          continue;

        if (map[ncur.x][ncur.y] == '|') {
          if(cur.x == ncur.x && map[cur.x][cur.y] == '|') {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y]; 
            queue[head++] = ncur;
//            cout << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          } else if(cur.x == ncur.x && map[cur.x][cur.y] != '-') {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y] + 1; 
            queue[head++] = ncur;
//            cout << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          }
        } else if (map[ncur.x][ncur.y] == '-') {
          if(cur.y == ncur.y && map[cur.x][cur.y] == '-') {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y]; 
            queue[head++] = ncur;
//            cout << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          } else if(cur.y == ncur.y && map[cur.x][cur.y] != '|') {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y] + 1; 
            queue[head++] = ncur;
//            cout << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          }
        } else if (map[ncur.x][ncur.y] == 'H') {
          if((cur.y == ncur.y && map[cur.x][cur.y] == '-')
          || (cur.x == ncur.x && map[cur.x][cur.y] == '|')
          || (map[cur.x][cur.y] == '.')
          || (map[cur.x][cur.y] == 'S')) {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y];
//            cout << "Reached home " << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          }
        } else if (map[ncur.x][ncur.y] == '.') {
          if((cur.y == ncur.y && map[cur.x][cur.y] == '-')
          || (cur.x == ncur.x && map[cur.x][cur.y] == '|')
          || map[cur.x][cur.y] == 'S'
          || map[cur.x][cur.y] == '.') {
            distance[ncur.x][ncur.y] = distance[cur.x][cur.y];
            queue[head++] = ncur;
//            cout << ncur.x << "," << ncur.y << " " << distance[ncur.x][ncur.y] << endl;
          }
        } 
      }
    }
  }

  int fewestCrossings(vector<string> const &map) {
    Position H = getPosition('H', map);
    Position S = getPosition('S', map);
    
//    display(map);
    Position cur = S;
    queue[head++] = cur;
    distance[S.x][S.y] = 0;
//    cout << "insert " << S.x << " " << S.y << " " << distance[S.x][S.y] << endl;

    while(tail < head) {
      cur = queue[tail++];
//      cout << "delete " << cur.x << " " << cur.y << " " << distance[cur.x][cur.y] << " " << head << " " << tail << endl;
      traverseTillEnd(cur, map);
    }
    return distance[H.x][H.y] != INT_MAX ? distance[H.x][H.y] : -1;
  }
};
