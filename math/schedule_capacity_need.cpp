#include <iostream>
using namespace std;

void showCapacity(int cap[], int capSize)
{
  int i;

  for(i = 0; i < capSize; i++)
  {
    cout << cap[i] << " ";
  }
  cout << endl;
}

int schedule(int need[], int capacity[], int needIndex, int needSize, int capSize)
{

  cout << "needIndex: " << needIndex << "  ";
  showCapacity(capacity, capSize);

  if(needIndex >= needSize) return true;

  int capIndex;

  for(capIndex = 0; capIndex < capSize; capIndex++)
  {
    if(capacity[capIndex] >= need[needIndex])
    {
      capacity[capIndex] -= need[needIndex];

      if(schedule(need, capacity, needIndex + 1, needSize, capSize)) return true;
      
      capacity[capIndex] += need[needIndex];
    }
  }
  return false;
}

int main()
{
  int capacity[] = {7, 9}; /* {8, 16, 8, 32} */
  int need[] = {3, 3, 3, 7}; /* {18, 4, 8, 4, 6, 6, 8, 8} */
  int capSize, needSize;

  capSize = sizeof(capacity)/sizeof(capacity[0]);
  needSize = sizeof(need)/sizeof(need[0]);

  cout << "Schedule: " << schedule(need, capacity, 0, needSize, capSize) << endl;

  return 0;
}
