#include <stdio.h>
#include <string.h>

void longestDupe(char *str, int size, int *maxStart, int *maxLen)
{
  char start, len, i;

  start = 0; len = 1;
//  printf("size=%d\n", size);
  for(i = 1; i < size; i++)
  {
//    printf("%c\n", str[i]);
    if(str[start] == str[i])
    {
      len++;
    }
    else
    {
      if(*maxLen < len)
      {
        *maxLen = len;
        *maxStart = start;
//        printf("=>%c %d\n", str[*maxStart], *maxLen);
      }
      start = i;
      len = 1;
    }
  }
}

int main()
{
  int maxStart = 0, maxLen = 0, i;
  char *str = "a";

  longestDupe(str, strlen(str), &maxStart, &maxLen);
  printf("%c %d\n", str[maxStart], maxLen);
  for(i = 0 ; i < maxLen; i++)
  {
    printf("%c", str[maxStart + i]);
  }
  printf("\n");
}
