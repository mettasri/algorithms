#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int versionComparision(char *pVer1, char *pVer2)
{
  /* ver1 >  ver2 => return 1 */
  /* ver1 == ver2 => return 0 */
  /* ver1 <  ver2 => return -1 */
  char *num1 = NULL;
  char *num2 = NULL;
  char *s_ver1, *s_ver2;

  num1 = strtok_r(pVer1, ".", &s_ver1);
  num2 = strtok_r(pVer2, ".", &s_ver2);

  while(num1 && num2)
  {
    if(atoi(num1) > atoi(num2))
      return 1;
    if(atoi(num1) < atoi(num2))
      return -1;

    num1 = strtok_r(NULL, ".", &s_ver1);
    num2 = strtok_r(NULL, ".", &s_ver2);
  }
  if(num1)
    return 1;
  if(num2)
    return -1;

  return 0;
}

int main()
{
  char ver1[50];
  char ver2[50];
  strcpy(ver1, "1.2"); strcpy(ver2, "1.2");
  printf("1.2,1.2: %d\n", versionComparision(ver1, ver2));

  strcpy(ver1, "9.0.4.1"); strcpy(ver2, "8.1.4.5");
  printf("9.0.4.1, 8.1.4.5: %d\n", versionComparision(ver1, ver2));
  
  strcpy(ver1, "9.0.4.10"); strcpy(ver2, "9.0.4.9");
  printf("9.0.4.10, 9.0.4.9: %d\n", versionComparision(ver1, ver2));
  
  strcpy(ver1, "9.0.4.1.0"); strcpy(ver2, "9.0.4.1");
  printf("9.0.4.1.0, 9.0.4.1: %d\n", versionComparision(ver1, ver2));
  
  strcpy(ver1, "19.0.14.1.0"); strcpy(ver2, "9.0.14.1.0");
  printf("19.0.14.1.0, 9.0.14.1.0: %d\n", versionComparision(ver1, ver2));
  
  strcpy(ver1, "19.0.14.1.0"); strcpy(ver2, "19.0.14.1.1");
  printf("19.0.14.1.0, 19.0.14.1.1: %d\n", versionComparision(ver1, ver2));
}
