#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

int maps[31];

struct QNode {
  int index;
  int height;
};

void displayQ(queue<QNode> temp)
{
  QNode q;
  cout << " =>> ";
  while(! temp.empty()) {
    q = temp.front();
    temp.pop();
    cout << setw(3) << q.index;
  }
  cout << endl;
}

/*
 * Ladder			  22	8						  26									                29
 * Table	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30
 * Snake																			            4		    7		    9						            1				
 *
 *Height
 *    0|                                1
 *     |  --------------------------------------------------------------------
 *    1|  2           3/22                  4             5/8            6   7
 *     |  -  ------------------------      ----    ----------------      -   -
 *    2|  8  23  24  25  26  27/1  28      9 10    11/26 12  13  14      X   X
 *     |  -  -   -
 *    3|  X  29  30
 */

int minPath()
{
  queue<QNode> qe;
  int len = 0, shortPath = 0;
  int visited[31];
  for(int i = 0; i < 31; i++)
    visited[i] = false;

  QNode front;
  front.index = 1;
  front.height = 0;
  qe.push(front);
  visited[1] = true;

  while(! qe.empty()) {
    front = qe.front();
    qe.pop();
    cout << front.index << " ";
    if(front.index == 30) {
      shortPath = front.height;
//      queue<QNode> temp = qe;
//    displayQ(temp);
      break;
    }
    
    for(int i = front.index + 1; i <= (front.index + 6) && i <= 30; ++i) {
      if(! visited[i]) {
        QNode a;
        if(-1 != maps[i]) {
          a.index = maps[i];
        } else {
          a.index = i;
        }
        a.height = front.height + 1;
        visited[i] = true;
        qe.push(a);
      }
    }
  }
  return shortPath;
}


int main()
{
  for (int i = 0; i < 31; i++) {
    maps[i] = -1;
  }
  // Ladders source and destination
  maps[3]  = 22;
  maps[5]  = 8;
  maps[11] = 26;
  maps[20] = 29;

  // Snakes source and destination
  maps[17] = 4;
  maps[19] = 7;
  maps[21] = 9;
  maps[27] = 1;
  
  cout << "min paths = " << minPath() << endl;
}
