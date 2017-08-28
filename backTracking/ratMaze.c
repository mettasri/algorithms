#include <stdio.h>
#include <stdbool.h>

#define N 4

int solveMaze(int maze[][N], int sol[][N], int x, int y)
{
  if(x == N - 1 && y == N - 1)
  {
    sol[x][y] = 1;
    return true;
  }

  if(x < N && y < N && maze[x][y])
  {
    sol[x][y] = 1;
    printf("(%d,%d): 1\n", x, y);
    if (solveMaze(maze, sol, x+1, y) == true)
      return true;
    if (solveMaze(maze, sol, x, y+1) == true)
      return true;
    else
    {
      sol[x][y] = 0;
      printf("(%d,%d): 0\n", x, y);
      return false;
    }
  }
  return false;
}

int main()
{
  int maze[N][N]  =  
  { {1, 1, 1, 0},
    {1, 0, 1, 1},
    {0, 1, 1, 0},
    {1, 1, 1, 1}
  };

  int sol[N][N] = 
  { {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };
  printf("Path present: %d\n", solveMaze(maze, sol, 0, 0));

  int i, j;
  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++)
      printf("%2d ", sol[i][j]);
    printf("\n");
  }
  printf("\n");

  return 0;
}
