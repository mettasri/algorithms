#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f1()
{
  int x;

  x = rand();
//  printf("Rand: %d\n", x);

  return (x%2);
}

int f29() {
       int radix = 2;
       int res;
       do {
       res = f1() * radix^4 + f1() * radix^3 + f1() * radix^2 + f1() * radix^1 + f1();
       } while (res > 29);
       return res;
}

int main()
{
  int i;

  srand ( time(NULL) );
  for(i = 0; i < 30; i++)
  {
    printf("%d ", f29());
  }
  printf("\n");
}
