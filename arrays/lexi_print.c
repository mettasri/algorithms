#include <iostream>
using namespace std;

void Test(int N, int k) 
{ 
  if (k > N) {return;} 
  cout << N << " " << k << endl;

  for(int i = 0; i<10; i++) 
  { 
    if (k <= N) 
    { 
      cout<<k<<endl; 

      k *= 10; 
      Test(N, k); 
      k /= 10; 
      k++; 
      if (k%10 == 0) return; 
    } 
  } 
} 

int main()
{
  Test(25, 1);
}
