#include <iostream>
#include<deque>
using namespace std;
 
void display(int buffer[], deque<int> &q)
{
  for(int i = 0; i < q.size(); ++i) {
    cout << buffer[q.at(i)] << " ";
  }
  cout << endl;
}

void slidingWindow(int buffer[], int n, int w, int output[])
{
   deque<int> Q;
   int i;
   /*Initilize deque Q for first window, put all W elements, however also
   removing elements which cannot be maximum in this window */
   for (i = 0; i < w; i++)
   {
   	   //This is where we are removing all less than elements
       while (!Q.empty() && buffer[i] >= buffer[Q.back()])
           Q.pop_back();
       // Pushing the index
       Q.push_back(i);
   }
   display(buffer, Q);
   for (i = w; i < n; i++)
   {
       output[i-w] = buffer[Q.front()];
 
       //update Q for new window
       while (!Q.empty() && buffer[i] >= buffer[Q.back()])
           Q.pop_back();
 
       //Pop older element outside window from Q    
       while (!Q.empty() && Q.front() <= i-w)
           Q.pop_front();
 
       //Insert current element in Q
       Q.push_back(i);
   }
   output[n-w] = buffer[Q.front()];
}
 
int main()
{
	int a[]={3,5,4,2,-1,4,0,-3};
	int n = sizeof(a)/sizeof(a[0]);
	int output[n - 3];
 
	slidingWindow(a,n,4,output);
  for(int i = 0; i < n - 3; i++ ) {
    cout << output[i] << " ";
  }
  cout << endl;
	return 0;
}

