#include <stdio.h>

void printArray(char arr[], int len)
{
  int i;

  for(i = 0; i < len; i++)
    printf("%c ", arr[i]);
  printf("\n");
}

void printStrFromNchar(int k, int setLen, char set[], int l, char str[], int ind)
{
  if(0 == k) {
    printArray(str, l);
    return;
  }

  int i;
  for(i = 0; i < setLen; i++) {
    str[l] = set[i];
    printStrFromNchar(k-1, setLen, set, l + 1, str, ind + 1);
  }
}

int main()
{
  int len = 0, k = 3, ind = 0, setLen;
  char set[] = {'a', 'b',};
  setLen = sizeof(set)/sizeof(set[0]);
  char str[3] = {'\0'};

  printStrFromNchar(k, setLen, set, len, str, ind);
}
