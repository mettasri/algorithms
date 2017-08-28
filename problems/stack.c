#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct s_stack
{
  int dataLen;
  int stackSize;
  int stackIndex;
  void *data;
} Stack;

stackInit(Stack *st, int dataSize) {
  st->dataLen = dataSize;
  st->stackSize = 5;
  st->stackIndex = 0;
  st->data = malloc(st->stackSize * st->dataLen);
}

void stackGrow(Stack *st)
{
  st->stackSize *= 2;
  st->data = realloc(st->data, st->stackSize * st->dataLen);
}

void push(Stack *st, void *data) {
  if(st->stackIndex == st->stackSize)  {
    printf("Stack full\n");
    stackGrow(st);
  }
  void *pTarget = st->data + st->stackIndex * st->dataLen;
  memcpy(pTarget, data, st->dataLen);
  st->stackIndex++;
}
void *pop(Stack *st, void *data) {
  if(! st->stackIndex)  {
    printf("Stack is empty\n");
    return;
  }

  void *pSource = st->data + (st->stackIndex - 1) * st->dataLen;
  st->stackIndex--;
  memcpy(data, pSource, st->dataLen);
}

int main()
{
  int x;
  int size = 10;
  int i;
  Stack st;

  stackInit(&st, sizeof(int));

  for(i = 0; i < size; i++)
  {
    x = 10* (i + 1);
    push(&st, (void *)&x);
  }

  printf("Stack contents: \n");
  for(i = 0; i < size + 1; i++)
  {
    pop(&st, &x); 
    printf("%d\n", x);
  }
}
