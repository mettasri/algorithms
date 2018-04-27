#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

struct Position {
  int x;
  int y;
};

enum DoorType { H, V };

struct DoorState {
  DoorType hv;
  int rotateCount;
  Position center;
  Position aSide[4];
  Position dSide[4];
};

struct MapDoors {
  static Position S;
  static Position E;
  int numDoors;
  DoorState door[10];
};
Position MapDoors::S;
Position MapDoors::E;

struct DoorRotate {
  int doorId;
  int dSideId;
  Position dSidePos;
};

struct QueueNode {
  DoorRotate curDoor;
  MapDoors mapDoors;
  bool doorLookup[10][4][1024];
};

int x_a[] = {0, 1,  0, -1};
int y_a[] = {1, 0, -1,  0};

int x_d[] = {-1, 1,  1, -1};
int y_d[] = { 1, 1, -1, -1};

class RevolvingDoors {
  queue<QueueNode> Queue; // 10 dSidePoss with 4 sides
  bool lookup[50][50];
public:
  Position getPosition(char loc, vector<string> const &map) {
    Position pos;

    pos.x = -1; pos.y = -1;
    for(int i = 0; i < map.size(); i++) {
      for(int j = 0; j < map[i].size(); j++) {
        if(loc == map[i][j])  {
          pos.x = i; pos.y = j;
          return pos;
        }
      }
    }
    return pos;
  }

  void displayMapDoors(MapDoors &map) {
    for(int d = 0; d < map.numDoors; d++) {
      cout << "****** " << d << " *****" << endl;
      cout << "hv    : " << map.door[d].hv << endl;
      cout << "center: " << map.door[d].center.x << " " << map.door[d].center.y << endl;
      int k;
      cout << "aSide : " ;
      for(k = 0; k < 4; k++) {
        cout << map.door[d].aSide[k].x << " " << map.door[d].aSide[k].y << ", ";
      }
      cout << endl;
      cout << "dSide : " ;
      for(k = 0; k < 4; k++) {
        cout << map.door[d].dSide[k].x << " " << map.door[d].dSide[k].y << ", ";
      }
      cout << endl;
    }
  }

  void updateMapDoor(MapDoors &mapDoors, vector<string> &map) {
    int ind = 0;
    mapDoors.S = getPosition('S', map);
    mapDoors.E = getPosition('E', map);

    Position pos, cent;
    int k;
    for(int i = 0; i < map.size(); i++) {
      for(int j = 0; j < map[i].size(); j++) {
        if('O' == map[i][j])  {
          cent.x = i; cent.y = j;

          mapDoors.door[ind].hv = H;
          if(map[i - 1][j] == '|') 
            mapDoors.door[ind].hv = V;
          
          mapDoors.door[ind].center = cent;
          for(k = 0; k < 4; k++) {
            pos.x = cent.x + x_a[k]; pos.y = cent.y + y_a[k];
            mapDoors.door[ind].aSide[k] = pos;
          }
          
          for(k = 0; k < 4; k++) {
            pos.x = cent.x + x_d[k]; pos.y = cent.y + y_d[k];
            mapDoors.door[ind].dSide[k] = pos;
          }
          
          mapDoors.door[ind].rotateCount = 0;

          ind++;
        }
      }
    }
    mapDoors.numDoors = ind;
  }

  void resetLookup() {
    for(int i = 0; i < 50; i++) {
      for(int j = 0; j < 50; j++)
        lookup[i][j] = false;
    }
  }
  
  void resetDoorLookup(bool doorLookup[10][4][1024]) {
    for(int d = 0; d < 10; d++) {
      for(int s = 0; s < 4; s++)
        for(int i = 0; i < 1024; i++)
        doorLookup[d][s][i] = false;
    }
  }

  int getDoorStateIndex(QueueNode &qnode) {
    int count = 0;
    MapDoors map = qnode.mapDoors;
    for(int d = 0; d < map.numDoors; d++) {
      count |= map.door[d].hv << d;
    }
    return count;
  }

  int getDoorRotCount(QueueNode &qnode) {
    MapDoors map = qnode.mapDoors;
    int count = 0;
    for(int d = 0; d < map.numDoors; d++) {
      count += map.door[d].rotateCount;
    }
    return count;
  }
  
  bool isEnd(Position const &pos, Position const &E) {
    if(pos.x == E.x && pos.y == E.y) {
//      cout << "*********REACHED END " << pos.x << " " << pos.y << " *******" << endl;
      return true;
    }
    return false;
  }

  void display(vector<string> map, QueueNode &qnode) {
    MapDoors mapdoors = qnode.mapDoors;
    DoorState door;
    for(int d = 0; d < mapdoors.numDoors; d++) {
      door = mapdoors.door[d];
      if(door.hv == H) {
        map[door.center.x][door.center.y] = 'H';
        map[door.center.x - 1][door.center.y] = ' ';
        map[door.center.x + 1][door.center.y] = ' ';
        map[door.center.x][door.center.y - 1] = '-';
        map[door.center.x][door.center.y + 1] = '-';
      } else {
        map[door.center.x][door.center.y] = 'V';
        map[door.center.x][door.center.y - 1] = ' ';
        map[door.center.x][door.center.y + 1] = ' ';
        map[door.center.x - 1][door.center.y] = '|';
        map[door.center.x + 1][door.center.y] = '|';
      }
    }
    map[qnode.curDoor.dSidePos.x][qnode.curDoor.dSidePos.y] = 'C';
    map[mapdoors.E.x][mapdoors.E.y] = 'E';
    for(int i = 0; i < map.size(); i++) {
      for(int j = 0; j < map[i].size(); j++)
        cout << map[i][j];
      cout << endl;
    }
  }

  void rotateDoor(QueueNode &qnode) {
    int d = qnode.curDoor.doorId;
    if(d == -1) return;

    qnode.mapDoors.door[d].rotateCount++;

    if(qnode.mapDoors.door[d].hv == H)
      qnode.mapDoors.door[d].hv = V;
    else
      qnode.mapDoors.door[d].hv = H;

    return;
  }

  void insertDoors(Position &pos, QueueNode &qnode) {
    QueueNode node = qnode;

    MapDoors map = node.mapDoors;
    int dState = getDoorStateIndex(node);
    for(int d = 0; d < map.numDoors; d++) {
      for(int s = 0; s < 4; s++) {
        if(map.door[d].dSide[s].x == pos.x && map.door[d].dSide[s].y == pos.y 
        && ! node.doorLookup[d][s][dState]) {
          node.doorLookup[d][s][dState] = true;
          node.curDoor.doorId = d;
          node.curDoor.dSideId = s;
          node.curDoor.dSidePos = pos;
          node.mapDoors = qnode.mapDoors;
          Queue.push(node);
//          cout << "insertDoors " << pos.x << " " << pos.y << endl;
        }
      }
    }
  }

  bool isOnDoorSide(Position const &pos, QueueNode &qnode) {
    MapDoors map = qnode.mapDoors;
    for(int i = 0; i < map.numDoors; i++) {
      if(map.door[i].hv == H) {
        if((map.door[i].aSide[0].x == pos.x && map.door[i].aSide[0].y == pos.y)
         ||(map.door[i].aSide[2].x == pos.x && map.door[i].aSide[2].y == pos.y)) {
          return true;
        }
      } else {
        if((map.door[i].aSide[1].x == pos.x && map.door[i].aSide[1].y == pos.y)
         ||(map.door[i].aSide[3].x == pos.x && map.door[i].aSide[3].y == pos.y)) {
          return true;
        }
      }
    }
    return false;
  }

  bool isOnDoorDiagonal(Position const &pos, QueueNode &qnode) {
    MapDoors map = qnode.mapDoors;
    for(int d = 0; d < map.numDoors; d++) {
      for(int s = 0; s < 4; s++) {
        if(map.door[d].dSide[s].x == pos.x && map.door[d].dSide[s].y == pos.y)
          return true;
      }
    }
    return false;
  }

  bool isOnDoorCenter(Position const &pos, vector<string> const &map) {
    return map[pos.x][pos.y] == 'O';
  }

  bool isOnWall(Position const &pos, vector<string> const &map) {
    return map[pos.x][pos.y] == '#';
  }

  bool isValid(Position const &pos, vector<string> const &map) {
    return (pos.x >= 0 && pos.x < map.size() && pos.y >= 0 && pos.y < map[0].size());
  }

  bool BFSTraverseToEnd(Position &pos, QueueNode &qnode, vector<string> &map) {
    Position npos;
    for(int i = 0; i < 4; i++) {
      npos.x = pos.x + x_a[i];
      npos.y = pos.y + y_a[i];
      if(isValid(npos, map) && !isOnWall(npos, map) 
        && !isOnDoorCenter(npos, map) && !lookup[npos.x][npos.y]) {
        lookup[npos.x][npos.y] = true;

        if(isOnDoorSide(npos, qnode) && isEnd(npos, qnode.mapDoors.E)) {
          rotateDoor(qnode);
          return true;
        } 

        if(isOnDoorSide(npos, qnode)) {
          continue;
        } 

        if(isEnd(npos, qnode.mapDoors.E)) {
          return true;
        } 

        if(isOnDoorDiagonal(npos, qnode)) {
          insertDoors(npos, qnode);
        }

        if(BFSTraverseToEnd(npos, qnode, map))
          return true;
      }
    }
    return false;
  }

  int turns(vector<string> &map) {
    QueueNode qnode;
    updateMapDoor(qnode.mapDoors, map);
    resetDoorLookup(qnode.doorLookup);
//    displayMapDoors(qnode.mapDoors);
    qnode.curDoor.doorId = -1;
    qnode.curDoor.dSideId = -1;
    qnode.curDoor.dSidePos = qnode.mapDoors.S;

    int minRotations = INT_MAX;

    resetLookup();
    lookup[qnode.mapDoors.S.x][qnode.mapDoors.S.y] = true;
    if(BFSTraverseToEnd(qnode.mapDoors.S, qnode, map)) {
      int count = getDoorRotCount(qnode);
      if(minRotations > count)
        minRotations = count;
    }
    
    while(! Queue.empty()) {
      qnode = Queue.front();
      Queue.pop();
      Position pos = qnode.curDoor.dSidePos;
//      cout << "START " << pos.x << " " << pos.y << endl;
      int d = qnode.curDoor.doorId;
      int s = qnode.curDoor.dSideId;

      rotateDoor(qnode);
//      display(map, qnode);
      int count = getDoorRotCount(qnode);
      if(minRotations != INT_MAX && minRotations <= count) {
//        cout << "Terminating long paths " << minRotations << endl;
        continue;
      }
      
      resetLookup();
      lookup[pos.x][pos.y] = true;
      if(BFSTraverseToEnd(pos, qnode, map)) {
        int count = getDoorRotCount(qnode);
        if(minRotations > count)
          minRotations = count;
      }
    }
    return minRotations == INT_MAX ? -1 : minRotations;
  }
};
