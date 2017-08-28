#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct employee
{
  int     emp_id;
  int     name_len;
  char    name[0];
}Employee;

int main()
{
  Employee *emp = malloc(sizeof(Employee) + (sizeof(char) * 16));

  emp->emp_id = 10;
  emp->name_len = 10;
  strcpy(emp->name, "Shridhar");

  printf("%d %d %s\n", emp->emp_id, emp->name_len, emp->name);

  return 0;
}
