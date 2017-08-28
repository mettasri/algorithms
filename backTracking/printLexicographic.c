#include <stdio.h>

/*
void printLexicographic(int n)
{
  int i, j;

  for(i = 1; i < 10; i++)
  {
    printf("%d\n", i);
    for(j = i * 10; j <= (i * 10 + 9) && j <= n; j++)
      printf("%d\n", j);
  }
}
*/

void printLexicographic(int n, int k)
{
  if(k > n)
    return;

  int i;
  for(i = 0; i < 10; i++)
  {
    if(k <= n)
    {
      printf("%d\n", k);
      k *= 10;
      printLexicographic(n, k);
      k /= 10;
    }
    k++;
    if(k % 10 == 0) 
      return;
  }
}
int main()
{
  printLexicographic(25, 1);

  return 0;
}
