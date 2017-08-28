// C program to reverse a linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
  int data;
  struct node* next;
};

/* Reverses the linked list in groups of size k and returns the 
   pointer to the new head node. */
node *reverseRecursive( node *head, int k)
{
  if(! head) return head;

  int count;
  node *newHead, *cur, *next;

  newHead = NULL;
  cur = head;
  count = 0;
  while(cur && count < k) {
    next = cur->next;
    
    cur->next = newHead;
    newHead = cur;

    cur = next;
    count++;
  }

  head->next = reverseRecursive(cur, k);
  return newHead;
}

void insertAfterFirst(node *head, node *temp)
{
  temp->next = head->next;
  head->next = temp;
}

node *reverseIterative(node *head, int k)
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
      count = 0;
      last = head;
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
//  head = reverseRecursive(head, 3);
  head = reverseIterative(head, 3);

  printf("\nreverse Linked list \n");
  printList(head);

  return(0);
}
