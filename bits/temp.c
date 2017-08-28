#include <iostream>
#include <math.h>
//-----------------------------------------
using namespace std;
//-----------------------------------------
typedef struct S_Pair
{
  unsigned int x;
  unsigned int y;
} Pair;

int combination(int n);
//-----------------------------------------
int solution(Pair *v, int size)
{
	unsigned int pair[2][2] = {{0},{0}};
	for (unsigned int i=0; i<size; i++)
	{
		int a= v[i].x % 2;
		int b =v[i].y % 2;
		pair[a][b]++;
	}

	int total = 0;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
	{
		total += combination( pair[i][j] );

		cout << "point: " << i <<":" << j ;
		cout << ", count: "<< pair[i][j] ;
		cout << ", sum: " << combination( pair[i][j] );
		cout << ", total: " << total << endl;
	}

	return total;
}
//-----------------------------------------
int combination(int n)
{
	return ( pow(n,2) - n ) / 2;
}
//----------------------------------------------
int main()
{
	/*Pair v[5] = {{1,1},
               {1,3},
			         {3,3},
			         {2,2},
			         {3,2}};*/
  Pair v[9] = {
               {4, 5},
               {8, 9},
               {1, 2},
               {4, 6},
               {3, 8},
               {8, 4},
               {9, 2},
               {8, 5},
               {8, 1}
             };

	cout << solution(v, 9) << endl;
}
