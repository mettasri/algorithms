// C++ program to construct the maximum sum linked
// list out of two given sorted lists
#include<iostream>
using namespace std;
 
//A linked list node
struct Node
{
    int data; //data belong to that node
    Node *next; //next pointer
};
 
// Push the data to the head of the linked list
void push(Node **head, int data)
{
    //Alocation memory to the new node
    Node *newnode = new Node;
 
    //Assigning data to the new node
    newnode->data = data;
 
    //Adjusting next pointer of the new node
    newnode->next = *head;
 
    //New node becomes the head of the list
    *head = newnode;
}
 
void displayList(Node *head)
{
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Method that adjusts the pointers and prints the final list
Node* finalMaxSumList(Node *a, Node *b)
{
  if(! a) return b;
  if(! b) return a;

  Node temp1, temp2, temp3;
  temp1.next = a;
  temp2.next = b;
  temp3.next = NULL;

  Node *prev1 = &temp1, *cur1 = a;
  Node *prev2 = &temp2, *cur2 = b;
  Node *cur = &temp3;
  int s1 = 0, s2 = 0;

  while(cur1 && cur2) {
    if(cur1->data < cur2->data) {
      s1 += cur1->data;
      cur1 = cur1->next;
    } else if(cur1->data > cur2->data) {
      s2 += cur2->data;
      cur2 = cur2->next;
    } else {
      if(s1 > s2) {
        cur->next = prev1->next;
        cur = cur1;
        prev1->next = cur1->next;
        cur1 = cur1->next;

        prev2 = cur2;
        cur2  = cur2->next;
      } else {
        cur->next = prev2->next;
        cur = cur2;
        prev2->next = cur2->next;
        cur2 = cur2->next;

        prev1 = cur1;
        cur1  = cur1->next;
      }
      s1 = 0;
      s2 = 0;
    }
  }
  while(cur1) {
    if(s1 > s2) {
      cur->next = prev1->next;
      prev1->next = cur1->next;
      cur1 = cur1->next;
      break;
    }
    s1 += cur1->data;
    cur1 = cur1->next;
  }
  while(cur2) {
    cout << cur2->data << " " << s1 << " " << s2 << endl;
    if(s1 < s2) {
      cur->next = prev2->next;
      prev2->next = cur2->next;
      cur2 = cur2->next;
      break;
    }
    s2 += cur2->data;
    cur2 = cur2->next;
  }

  return temp3.next;
}

//Main driver program
int main()
{
  //Linked List 1 : 1->3->30----->90->110->120->NULL
  //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
  Node *head1 = NULL, *head2 = NULL, *head;
  push(&head1, 120);
  push(&head1, 110);
  push(&head1, 90);
  push(&head1, 30);
  push(&head1, 3);
  push(&head1, 1);

  push(&head2, 130);
  push(&head2, 120);
  push(&head2, 100);
  push(&head2, 90);
  push(&head2, 32);
  push(&head2, 12);
  push(&head2, 3);
  push(&head2, 0);

  displayList(head1);
  displayList(head2);

  head = finalMaxSumList(head1, head2);

  //    displayList(head1);
  //    displayList(head2);
  displayList(head);

  return 0;
}
