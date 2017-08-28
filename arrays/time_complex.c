#include <stdio.h>

void fun(int n)
{
   int j = 1, i = 0;
   while (i < n)
   {
       // Some O(1) task
       i = i + j;
       printf("%d ", i);
       j++;
   }
   printf("\n");
}

int main()
{
  fun(4);
  fun(9);
  fun(16);
  fun(25);
}
