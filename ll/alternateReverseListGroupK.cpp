// C program to reverse a linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
  int data;
  struct node* next;
};

void insertAfterFirst(node *head, node *temp)
{
  temp->next = head->next;
  head->next = temp;
}

node *alternateReverseIterative(node *head, int k)
{
  int count;
  node *cur, *next, *last;
  node newHead;

  newHead.next = NULL;
  cur = head;
  last = &newHead;
  count = 0;

  while(cur) {
    next = cur->next;

    insertAfterFirst(last, cur);
    count++;

    if(count == k) {
      last = head;
    } else if(count > k && count < 2*k) {
      last = cur;
    } else if(count == 2*k) {
      count = 0;
      last = cur;
      head = next;
    }
    
    cur = next;
  }

  return newHead.next;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push( node** head_ref, int new_data)
{
  /* allocate node */
  node* new_node =
    ( node*) malloc(sizeof( node));

  /* put in the data  */
  new_node->data  = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ref);    

  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList( node *node)
{
  while (node != NULL)
  {
    printf("%d  ", node->data);
    node = node->next;
  }
  printf("\n");
}    

/* Drier program to test above function*/
int main(void)
{
  /* Start with the empty list */
  node* head = NULL;

  /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
  push(&head, 12);
  push(&head, 11);
  push(&head, 10);
  push(&head, 9);
  push(&head, 8);
  push(&head, 7);
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);           

  printf("Given linked list \n");
  printList(head);
  head = alternateReverseIterative(head, 3);

  printf("\nreverse Linked list \n");
  printList(head);

  return(0);
}
