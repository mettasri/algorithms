#include <stdio.h>
/*
int binarySearch(int arr[], int l, int h, int k)
{
  printf("%d %d\n", l, h);
  if(h >= l)
  {
    int mid = (l + h)/2;
    if(k == arr[mid]) return mid;

    if(k < arr[mid]) return binarySearch(arr, l, mid - 1, k);
    else return binarySearch(arr, mid + 1, h, k);
  }
  return -1;
}
*/
int ceilInArray(int arr[], int l, int h, int k)
{
  printf("%d %d\n", l, h);
  if(h >= l)
  {
    int mid = (l + h)/2;
    if(k <= arr[l])  return l;
    if(k == arr[mid]) return mid;
    else if(l <= (mid - 1) && ((k > arr[mid -1]) && (k < arr[mid])))  return mid;
    else if(h >= (mid + 1) && ((k > arr[mid]) && (k < arr[mid + 1])))  return mid + 1;

    if(k < arr[mid]) return ceilInArray(arr, l, mid - 1, k);
    else return ceilInArray(arr, mid + 1, h, k);
  }
  return -1;
}

void printArray(int arr[], int n)
{
  int i;
  for(i = 0; i < n; i++)
    printf("%2d ", i);
  printf("\n");
  for(i = 0; i < n; i++)
    printf("%2d ", arr[i]);
  printf("\n");
}

/* Driver program to check above functions */
int main()
{
   int arr[] = {1, 2, 8, 10, 11, 12, 19};
   int n = sizeof(arr)/sizeof(arr[0]);
   
   printArray(arr, n);
/*
   while(1)
   {
     int x;
     printf("Enter: "); scanf("%d", &x);
     int index = binarySearch(arr, 0, n-1, x);
     if(index == -1)
       printf("%d doesn't exist in array\n", x);
     else 
       printf("Found at index %d\n", index);
   }
*/
   while(1)
   {
     int x;
     printf("Enter: "); scanf("%d", &x);
     int index = ceilInArray(arr, 0, n-1, x);
     if(index == -1)
       printf("ceilInArray doesn't exist in array\n");
     else 
       printf("ceilInArray is: %d\n", arr[index]);
   }
   return 0;
}


