#include <iostream>
#include <algorithm>
using namespace std;

class meetingTime
{
  public:
    int startTime;
    int endTime;
};

int minNoOfMeetingRoomsReq(int *start,  int *end, int n)
{
  int i = 0, j = 0;
  int roomsNeeded = 0;
  int maxRooms = 0;

  while(i < n && j < n) {
    if(start[i] < end[j]) {
      roomsNeeded++;
      cout << start[i] << " " << roomsNeeded << endl;
      i++;
      if(maxRooms < roomsNeeded)  {
        maxRooms = roomsNeeded;
      }
    } else  {
      roomsNeeded--;
      cout << end[i] << " " << roomsNeeded << endl;
      j++;
    }
  }
  return maxRooms;
}

int main()
{
  int start[] = {900,  940, 950,  1100, 1500, 1800};
  int end[]   = {910, 1200, 1120, 1130, 1900, 2000};
  int size = sizeof(start)/sizeof(int);

  sort(start, start + size);
  sort(end, end + size);

  cout << "Max meeting rooms: " << minNoOfMeetingRoomsReq(start, end, size) << endl;
}
