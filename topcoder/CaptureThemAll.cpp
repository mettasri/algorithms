#include <vector>
#include <string>
using namespace std;

struct Position {
  int x;
  int y;
};

class CaptureThemAll {
  vector<int> x_move;
  vector<int> y_move;
public:
  CaptureThemAll()  {
    int x[] = {-2, -2,  2, 2, -1, -1,  1, 1};
    int y[] = {-1,  1, -1, 1, -2,  2, -2, 2};
    
    x_move.assign(x, x+8);
    y_move.assign(y, y+8);
  }
  Position getPosition(string const &p) {
    Position pos;
    pos.x = p[0] - 'a';
    pos.y = p[1] - '1';
    return pos;
  }
  
  int getDistance(Position start, Position finish) {
    vector<vector<int>> distance(8, vector<int>(8, -1));
    Position pos, npos;
    Position queue[64];
    int head = 0, tail = 0;
    
    distance[start.x][start.y] = 0;
    queue[head++] = start;

    while(tail < head) {
      pos = queue[tail++];

      if(pos.x == finish.x && pos.y == finish.y) 
        return distance[pos.x][pos.y];

      for(int i = 0; i < 8; i++) {
        npos.x = pos.x + x_move[i];
        npos.y = pos.y + y_move[i];
        if(npos.x >= 0 && npos.x < 8 && npos.y >= 0 && npos.y < 8) {
          if(distance[npos.x][npos.y] == -1) {
            distance[npos.x][npos.y] = distance[pos.x][pos.y] + 1;
            queue[head++] = npos;
          }
        }
      }
    }
  }

  int fastKnight(string const &knight,
                 string const &rook,
                 string const &queen) {
    Position k = getPosition(knight);
    Position r = getPosition(rook);
    Position q = getPosition(queen);

    int kr = getDistance(k, r);
    int kq = getDistance(k, q);
    int rq = getDistance(r, q);

    return min(kr, kq) + rq;

    return 0;
  }
};
