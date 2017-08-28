// C program to remove intermediate points in a linked list 
// that represents horizontal and vertical line segments
#include <stdio.h>
#include <stdlib.h>

// Node has 3 fields including x, y coordinates and a pointer
// to next node
struct node
{
	int x, y;
	struct node *next;
};

/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int x,int y)
{
	struct node* new_node = 
		(struct node*) malloc(sizeof(struct node));
	new_node->x = x;
	new_node->y = y;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("(%d,%d)-> ", temp->x,temp->y);
		temp = temp->next;
	}
	printf("\n");

}

// Utility function to remove Next from linked list 
// and link nodes after it to head
void deleteNode(struct node *head, struct node *Next)
{
	head->next = Next->next;
	Next->next = NULL;
	free(Next);
}

// This function deletes middle nodes in a sequence of
// horizontal and vertical line segments represented by
// linked list.
struct node* deleteMiddle(struct node *head)
{
  node *p1, *p2, *p3;

  p1 = head;
  while(p1 && p1->next && p1->next->next) {
    p2 = p1->next;
    p3 = p2->next;

    if((p1->x == p2->x && p2->x == p3->x) || (p1->y == p2->y && p2->y == p3->y)) {
      p1->next = p3;
      free(p2);
    } else {
      p1 = p1->next;
    }
  }

  return head;
}

// Driver program to tsst above functions
int main()
{
	struct node *head = NULL;

	push(&head, 40,5);
	push(&head, 20,5);
	push(&head, 10,5);
	push(&head, 10,8);
	push(&head, 10,10);
	push(&head, 3,10);
	push(&head, 1,10);
	push(&head, 0,10);
	printf("Given Linked List: \n");
	printList(head);

	if (deleteMiddle(head) != NULL);
	{
		printf("Modified Linked List: \n");
		printList(head);
	}
	return 0;
}

