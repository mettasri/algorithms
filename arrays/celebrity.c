#include <iostream>
#include <list>
using namespace std;

// Max # of persons in the party
#define N 8

static int count = 0;
// Celebrities identified with numbers from 0 through size-1
int size = 4;
// Person with 2 is celebrity
//bool MATRIX[N][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
bool MATRIX[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
//bool MATRIX[N][N] = {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};

bool HaveAcquiantance(int a, int b) { 
  count++;
  cout << a << ", " << b << endl;
  return MATRIX[a][b]; 
}

int CelebrityUsingStack(int size) {
  // Handle trivial case of size = 2

  list<int> stack; // Careful about naming
  int i;
  int C; // Celebrity

  i = 0;
  while( i < size )
  {
    stack.push_back(i);
    i = i + 1;
  }

  int A = stack.back();
  stack.pop_back();

  int B = stack.back();
  stack.pop_back();

  while( stack.size() != 1 )
  {
    if( HaveAcquiantance(A, B) )
    {
      A = stack.back();
      stack.pop_back();
    }
    else
    {
      B = stack.back();
      stack.pop_back();
    }
  }

  // Potential candidate?
  C = stack.back();
  stack.pop_back();

  // Last candidate was not examined, it leads one excess comparison (optimise)
  if( HaveAcquiantance(C, B) )
    C = B;

  if( HaveAcquiantance(C, A) )
    C = A;

  cout << endl;

  // I know these are redundant,
  // we can simply check i against C
  i = 0;
  while( i < size )
  {
    if( C != i )
      stack.push_back(i);
    i = i + 1;
  }

  while( !stack.empty() )
  {
    i = stack.back();
    stack.pop_back();

    // C must not know i
    if( HaveAcquiantance(C, i) )
      return -1;

    // i must know C
    if( !HaveAcquiantance(i, C) )
      return -1;
  }

  return C;
}

int main() {
  int id = CelebrityUsingStack(size);
  id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id << endl;;
  cout << "Total comparisions: " << count << endl;
  return 0;
}

