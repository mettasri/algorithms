#include <stdio.h>

int printPath(int path[][8])
{
  int i, j;

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++)
      printf("%2d ", path[i][j]);
    printf("\n");
  }
  printf("\n");
}

int knightTour(int path[][8], int pos, int x, int y, int xCord[], int yCord[])
{
  if(pos == 64)
  {
    printf("Result: \n");
    printPath(path);
    return 1;
  }

  int i;
  int xi, yi;

  for(i = 0; i < 8; i++)
  {
    xi = x + xCord[i];
    yi = y + yCord[i];
    if(xi >= 0 && xi < 8 && yi >= 0 && yi < 8 && path[xi][yi] == -1)
    {
      path[xi][yi] = pos;
//      printf("(%d %d) (%d,%d)=%d\n", xi, yi, xi, yi, pos);
      if(knightTour(path, pos+1, xi, yi, xCord, yCord))
        return 1;

      path[xi][yi] = -1;
    }
  }
  return 0;
  
}

int main()
{
  int i, j;
  int path[8][8];

  int xCord[] = {2, 1, -1, -2, -2, -1,  1,  2};
  int yCord[] = {1, 2,  2,  1, -1, -2, -2, -1};

  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      path[i][j] = -1;

  path[1][1] = 0;
  knightTour(path, 1, 1, 1, xCord, yCord);

//  printPath(path);
}
