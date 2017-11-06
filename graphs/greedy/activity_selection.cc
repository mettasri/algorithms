// Greedy Algorithms | Set 1 (Activity Selection Problem)
// Problem statement: You are given n activities with their start and finish times.
//  Select the maximum number of activities that can be performed by a single person,
//  assuming that a person can only work on a single activity at a time
#include <iostream>
#include <vector>
#include <algorithm>

class Activity {
 public:
  Activity(int s, int f) : start(s), finish(f) {}
  ~Activity() {}
  
  void Display() const {
    std::cout << "(" << start << " " << finish << ") ";
  }
  
  friend bool ActivityCompare(const Activity& a1, const Activity& a2);
  friend void GetMaxActivities(const std::vector<Activity>& jobs, std::vector<int>& result);

 private:
  int start, finish;
};

bool ActivityCompare(const Activity& a1, const Activity& a2) {
  return a1.finish < a2.finish;
}

// Time Complexity
//  if activities are
//    sorted: O(n)
//    unsorted: O(nlogn) + O(n) = O(nlogn)
//
void GetMaxActivities(const std::vector<Activity>& jobs, std::vector<int>& result) {
  result.push_back(0);
  for (int i = 1; i < jobs.size(); ++i) {
    if (jobs[result.back()].finish <= jobs[i].start) {
      result.push_back(i);
    }
  }
}

int main() {
  std::vector<Activity> jobs = {Activity(5, 9), Activity(1, 2), Activity(3, 4),
                                Activity(0, 6), Activity(5, 7), Activity(8, 9)};

  sort(jobs.begin(), jobs.end(), ActivityCompare);
  for (const auto job : jobs) {
    job.Display();
  }
  std::cout << std::endl;
  
  std::vector<int> result;
  GetMaxActivities(jobs, result);
  
  for (const auto i : result) {
    jobs[i].Display();
  }
  std::cout << std::endl;

  return 0;
}
