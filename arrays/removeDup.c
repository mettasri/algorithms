#include <stdio.h>

void removeDup(int *str, int size)
{
  int r = 0, w = 1;
  int c = str[r];

  for(r = 1; r < size; r++)
  {
    if(str[r] != c)
    {
      str[w++] = str[r];
      c = str[r];
    }
  }
}

int main()
{
//  char str[] = "Helllo";
  int arr[] = {3, 3, 4, 5, 5, 6, 7, 7, 7};
  int size = sizeof(arr)/sizeof(arr[0]);
  int i;

  removeDup(arr, size);
  for(i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

