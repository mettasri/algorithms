#include <iostream>
using namespace std;
//void swap(char *x, char *y)
//{
//	char temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//
//bool isSimTogether(char *a, int size){
//	for (int i = 0; i < size; i++){
//		if (a[i] == a[i + 1])
//			return true;
//	}
//	return false;
//}
//
//void permute(char *a, int l, int r)
//{
//	int i;
//	if (l == r && !isSimTogether(a,r)){
//		printf("%s\n", a);
//	}
//	else
//	{
//		for (i = l; i <= r; i++)
//		{
//			if (l == i) continue;
//			swap((a + l), (a + i));
//			permute(a, l + 1, r);
//			swap((a + l), (a + i)); 
//		}
//	}
//}

void swap(char &a, char &b)
{
  char temp;
  temp = a;
  a = b;
  b = temp;
}

int main()
{
//	char str[] = "AAAACCCCBB";
//  char str[] = "ABCCC";
//  int n = sizeof(str) / sizeof(str[0]) - 1;
//  permute(str, 0, n - 1);
  int curr = 0, next = 1;
//	char str[] = "AAAACCCCBB";
  char str[] = "ABCCC";
//  char str[] = {'A', 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'C', 'A', 'D', '\0'};
  while (str[curr] != '\0')
  {
    if(str[curr] == str[next])
    {
      next++;
      continue;
    }
    else
    {
      swap(str[curr+1], str[next]);
      curr++;
    }
  }
  cout << str << endl;
  return 0;
}
