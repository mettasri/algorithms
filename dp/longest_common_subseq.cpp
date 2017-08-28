/* Dynamic Programming implementation of LCS problem */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b);

/*
int lcs(string X, string Y)
{
  cout << X << "  " << Y << endl;
  int m = X.length();
  int n = Y.length();
  if (m == 0 || n == 0)
    return 0;
  if (X[m-1] == Y[n-1])
    return 1 + lcs(X.substr(0, m-1), Y.substr(0, n-1));
  else
    return max(lcs(X, Y.substr(0, n-1)), lcs(X.substr(0, m-1), Y));
}

int max(int a, int b)
{
  return (a > b)? a : b;
}
*/

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
  int L[m+1][n+1];
  int i, j;
/*
  for (i=0; i<=m; i++)
  {
    for (j=0; j<=n; j++)
    {
      L[i][j] = 0;
    }
  }
*/
  /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i=0; i<=m; i++)
  {
    for (j=0; j<=n; j++)
    {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (X[i-1] == Y[j-1])
        L[i][j] =  L[i-1][j-1] + 1;

      else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
  }

  printf("%4c", ' ');
  for (j=1; j<=n; j++)
  {
    printf("%2c", Y[j-1]);
  }
  printf("\n");
  for (i=0; i<=m; i++)
  {
    for (j=0; j<=n; j++)
    {
      if(i == 0 && j == 0)
        printf("%2c", ' ');
      else if((j == 0)&&(i > 0))
        printf("%2c", X[i-1]);
      printf("%2d", L[i][j]);
    }
    printf("\n");
  }

  char lcsStr[m];
  int len = L[m][n];
  lcsStr[len] = '\0';
  while(L[m][n])
  {
    /* diagonal */
    if((L[m][n] == L[m-1][n-1] + 1) && (L[m-1][n] != L[m][n]) && (L[m][n-1] != L[m][n]))
    {
//      printf("%d %c %c\n", L[m][n], X[m-1], Y[n-1]);
    lcsStr[L[m][n] - 1] = X[m - 1];
      m = m - 1;
      n = n - 1;
    }
    /* left */
    else if(L[m][n-1] == L[m][n])
    {
      n = n - 1;
    }
    else /* up */
    {
      m = m - 1;
    }
  }
  L[m][n] = len;
  printf("%s\n", lcsStr);

  /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
  return L[m][n];

}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
  return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{
  int m;
  int n;
  char X[32];
  char Y[32];

  strcpy(X, "GXTXAYB");
  strcpy(Y, "AGGTAB");
  m = strlen(X);
  n = strlen(Y);
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );


  strcpy(X, "ABCDGH");
  strcpy(Y, "AEDFHR");
  m = strlen(X);
  n = strlen(Y);
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  strcpy(X, "AGGTAB");
  strcpy(Y, "GXTXAYB");
  m = strlen(X);
  n = strlen(Y);
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  return 0;
}
