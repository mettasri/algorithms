#include <stdio.h>

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
            printf("result: %d\n", result);
        }
        exp >>= 1;
        base *= base;
        printf("base: %d\n", base);
    }

    return result;
}

int main()
{
  printf("%d\n", ipow(2, 5));
  return 0;
}
