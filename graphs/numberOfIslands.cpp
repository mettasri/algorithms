#include <iostream>
using namespace std;
#define R 5
#define C 5

static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void DFS(int islands[][C], int visited[][C], int i, int j)
{
  visited[i][j] = 1;
  cout << i <<" " << j << endl;
  for(int k = 0; k < 8; k++)
  {
    unsigned int i_temp = i + rowNbr[k];
    unsigned int j_temp = j + colNbr[k];

    if((i_temp < R && j_temp < C) && islands[i_temp][j_temp] && !visited[i_temp][j_temp])
    {
      DFS(islands, visited, i_temp, j_temp);
    }
  }
}

int main()
{
  int islands[R][C] =  {
                        {1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}
                      };
  int visited[R][C] = {0};
  int count = 0;

  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
    {
      if(islands[i][j] && !visited[i][j])
      {
        DFS(islands, visited, i, j);
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
