#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "this,is.a sample  string  ";
  char *pch = NULL;
  int i = 0;

  pch = strtok(str, " .,");
  while(pch != NULL) {
    printf("%d) %s\n", i++, pch);
    pch = strtok(NULL, " .,");
  }

  return 0;
}
