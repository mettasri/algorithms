#include<stdio.h>
 
void printarray(int a[], int n);
int partition( int a[], int low, int high );
void swap (int a[], int left, int right)
{
 int temp;
 temp=a[left];
 a[left]=a[right];
 a[right]=temp; 
}//end swap
 
void quicksort( int a[], int low, int high )
{
 int pivot;
 // Termination condition! 
 if ( high > low )
 {
  pivot = partition( a, low, high );
  quicksort( a, low, pivot-1 );
  quicksort( a, pivot+1, high );
 }
} //end quicksort
 
int partition( int a[], int low, int high )
{
 int left, right;
 int pivot_item;
 int pivot = left = low; 
 pivot_item = a[low]; 
 right = high;
 while ( left < right ) 
 {
  // Move left while item < pivot 
  while( a[left] <= pivot_item ) 
   left++;
  // Move right while item > pivot 
  while( a[right] > pivot_item ) 
   right--;
  if ( left < right ) 
   swap(a,left,right);
 }
 
 printarray(a, high+1);

 // right is final position for the pivot 
 a[low] = a[right];
 a[right] = pivot_item;
 return right;
}//end partition
 
// void quicksort(int a[], int, int);
void printarray(int a[], int);
 
int main()
{
 int a[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
 int i, n;
 printf("\nUnsorted elements: \n");
 printarray(a,10);
 quicksort(a,0,9);
 printf("\nSorted elements: \n");
 printarray(a,10);
 
}//end main
 
 
void printarray(int a[], int n)
{
 int i;
 for (i=0; i<n; i++)
  printf(" %d ", a[i]);
 printf("\n");
}//end printarray
