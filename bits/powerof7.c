#include<stdio.h>
#define bool int
 
/* Function to check if x is power of 2*/
bool isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%7 != 0)
      return 0;
    n = n/7;
  }
  return 1;
}
 
/*Driver program to test above function*/
int main()
{
  isPowerOfTwo(14)? printf("Yes\n"): printf("No\n");
  isPowerOfTwo(49)? printf("Yes\n"): printf("No\n");
  isPowerOfTwo(16)? printf("Yes\n"): printf("No\n");
  isPowerOfTwo(2)? printf("Yes\n"): printf("No\n");
  isPowerOfTwo(18)? printf("Yes\n"): printf("No\n");
  isPowerOfTwo(1)? printf("Yes\n"): printf("No\n");
  return 0;
}
