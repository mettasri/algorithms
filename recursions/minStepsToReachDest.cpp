// Given a number line from -infinity to +infinity. You start at 0 and can go either to the left or to the right. The condition is that in i’th move, you take i steps.
// a) Find if you can reach a given number x
// b) Find the most optimal way to reach a given number x, if we can indeed reach it. For example, 3 can be reached om 2 steps, (0, 1) (1, 3) and 4 can be reached in 3 steps (0, -1), (-1, 1) (1, 4).
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
using namespace std;
 
// Function to count number of steps required to reach a
// destination.
// source -> source vertex
// step -> value of last step taken
// dest -> destination vertex
int steps(int source, int step, int dest)
{
  // base cases
  if (abs(source) > (dest))  return INT_MAX;
  if (source == dest)     return step;

  // at each point we can go either way
  // minimum of both cases
  return min(steps(source+step+1, step+1, dest), 
             steps(source-step-1, step+1, dest));
}

// Driver Program
int main()
{
  int dest = 4;
  cout << "No. of steps required to reach "
    << dest << " is " << steps(0, 0, dest);
  return 0;
}
