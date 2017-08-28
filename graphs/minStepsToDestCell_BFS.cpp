#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <queue>
using namespace std;
/*  	 0 1 2 3
 *  	--------
 *  0	|0 0 0 0
 *  1	|1 0 1 0
 *  2	|1 0 0 0
 *
 *  2,3 (5)
 *    2,2 (4)
 *    | 2,1 (3)
 *    |   1,1 (2)
 *    |     0,1 (1)
 *    |     | 0,0 (0)
 *    |     0,2 (-1)
 *    |       0,3 (-1)
 *    |         1,3 (-1)
 *    |
 *    1,3 (4)
 *      0,3 (3)
 *        0,2 (2)
 *          0,1 (1)
 *            0,0 (0)
 *            1,1 (-1)
 *              2,1 (-1)
 *                2,2 (-1)
 */

int getMinStepsDFS(int maze[][4], bool visited[][4], int row, int col, int ROWS, int COLS, int ind)
{
//  cout << setw(2*ind) << row << "," << col << endl;
  if(maze[row][col])
    return -1;
  if(0 == row && 0 == col) {
//    cout << setw(2*ind) << row << "," << col << ": 0" << endl;
    return 0;
  }

  int minSteps = -1;
  int curSteps = -1;

  int x[] = { 0, 0,-1, 1};
  int y[] = {-1, 1, 0, 0};
  for(int i = 0; i < 4; ++i) {
    int r = row + x[i];
    int c = col + y[i];

    if(r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] == 0 && !visited[r][c]) {
      visited[r][c] = true;
      curSteps = getMinStepsDFS(maze, visited, r, c, ROWS, COLS, ind + 1);

      if(curSteps != -1 && minSteps != -1) {
        minSteps = min(curSteps, minSteps);
      } else { /* either of one value is -ve */
        minSteps = max(curSteps, minSteps);
      }
      visited[r][c] = false;
    }
  }
//  if(minSteps != -1)
//    minSteps += 1;
//  cout << setw(2*ind) << row << "," << col << ": " << minSteps << endl;
  return (minSteps != -1 ? minSteps + 1 : minSteps);
}

struct QNode {
  int x;
  int y;
};

int getMinStepsBFS(int maze[][4], bool visited[][4], int row, int col, int ROWS, int COLS)
{
  if(maze[0][0] || (row == 0 && col == 0)) {
    return -1;
  }
  if(maze[row][col]) {
    return -1;
  }
  int minSteps = 0, n = 0;
  int xCord[] = { 0, 0,-1, 1};
  int yCord[] = {-1, 1, 0, 0};
  queue<QNode> q;
  QNode node, temp;

  visited[row][col] = true;
  node.x = row;
  node.y = col;
  q.push(node);

  while(! q.empty()) {
    n = q.size();
    while(n) {
      n--;
      node = q.front();
      q.pop();

      for(int i = 0; i < 4; ++i) {
        int r = node.x + xCord[i];
        int c = node.y + yCord[i];
        
        if(r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] == 0 && !visited[r][c]) {
          visited[row][col] = true;
          if(r == 0 && c == 0) {
            return minSteps + 1;
          }
          temp.x = r;
          temp.y = c;
          q.push(temp);
        }
      }
    }
    if(q.size()) {
      minSteps++;
    }
  }

  return -1;
}

int main()
{
  int maze[3][4] = {{0, 0, 0, 0},
                    {1, 0, 1, 0},
                    {1, 0, 0, 0}};

  bool visited[3][4];

  // BFS -> find the fewest num of steps needed to reach a certain end point from the 
  // starting one
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      memset(visited, false, 3*4);
      cout << i << " " << j << ": " << getMinStepsBFS(maze, visited, i, j, 3, 4) << endl;
    }
  }

  // DFS
  memset(visited, false, 3*4);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 4; j++)
      cout << i << " " << j << ": " << getMinStepsDFS(maze, visited, i, j, 3, 4, 0) << endl;


  return 0;
}
