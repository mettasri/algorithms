#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int selectPivot(int s, int e) {
//  return (s+e)/2;
//  return s;
  return e;
}

int partition(int *v, int s, int e) {
  int p = selectPivot(s, e);
  // . . . . . . . . . . .
  // h                   l
  // swap(h, l) if h > l
  int h = s; 
  int l = e; 
  // run loop till h & l cross each other
  while(h <= l) {
    if((h != p && l != p) && (v[h] >= v[p] && v[p] >= v[l])) {
      swap(v[h], v[l]);
      cout << "swap " << h << " " << l << endl;
//      h++; l--;
//      continue;
    }

    if(v[h] >= v[p] && v[p] >= v[l]) continue;
    if(v[h] <= v[p]) h++;
    
    if(v[l] >= v[p]) l--;

  }
  cout << l << " " << p << " " << h << endl;
  /* P ..... L H .. */
  if(p < l && v[p] > v[l]) {
    swap(v[p], v[l]); p = l;
  }
  /* .. L H .....P. */
  else if(h < p && v[p] < v[h]) {
    swap(v[p], v[h]); p = h;
  }
  /* .. L P H ..... */
  else if(l < p && p < h && v[p] < v[l]) {
    swap(v[p], v[l]); p = l;
  }

  return p;
}

void display(int *v, int i, int n) {
  while(i <= n) {
    cout << v[i] << " ";
    i++;
  }
  cout << endl;
}

void quicksort(int *v, int s, int e) {
  if(s >= e) return;
  cout << s << " " << e << endl;

  int p = partition(v, s, e);
  cout << "=========" << endl;

  display(v, s, e);
  quicksort(v, s, p - 1);
  quicksort(v, p + 1, e);
}

int main() {
//  int v[] = { 6, 7, 8, 1, 2, 3, 4, 5, 9, 10 };
//  int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//  int v[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  int v[] = { 10, 9, 8, 7, 6, 5, 4, 3, 1, 10 };
//  int v[] = { 0, 1, 0, 1, 0, 0, 1, 0, 0, 0 };
  int n = sizeof(v)/sizeof(v[0]);

  quicksort(v, 0, n - 1);
  display(v, 0, n - 1);

  return 0;
}
