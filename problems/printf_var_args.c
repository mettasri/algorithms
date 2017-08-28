#include <stdio.h>
#include <stdarg.h>

void myPrintf(const char *fmt, ...)
{
  int i;
  va_list argp;

  va_start(argp, fmt);

  printf("%d\n", va_arg(argp, int));
  putchar (va_arg(argp, int)); putchar('\n');
  printf("%f\n", va_arg(argp, double));
  printf("%s\n", va_arg(argp, char*));
  
  va_end(argp);
}

int main()
{
//  myPrintf("values are: %d %c %f", 10, 'a', 4.5);
//  myPrintf("%d%c%d", 10, 'a', 30);
  myPrintf("%d%c%f%s", 10, 'a', 30.6, "hello");
}
