#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}

  static ListNode* getNewNode(int val) {
    return new ListNode(val);
  }

  void displayList() {
    cout << val << " ";
    if (!next) {
      cout << endl;
      return;
    }
    next->displayList();
  }

};

/*
 * 0	1 X	(n = 1)
 * p1   p2
 *
 * 0	1	2	X (n = 1)
 *    p1  p2
 *
 * 0	1	2	X (n = 2)
 * p1     p2
 *
 * 0	1	2	3	4	X (n = 2)
 *      p1    p2
 */
class Solution {
 public:
  ListNode* removeNthNodeFromLast(ListNode *head, int n) {
		if (n <= 0 || !head)	return head;
		ListNode *new_head = ListNode::getNewNode(0);
		new_head->next = head;

		ListNode *fast;
		for (fast = head; fast && n; fast = fast->next, --n);
		if (n > 0)	return new_head->next; // short list

		ListNode *slow;
		for (slow = new_head; fast; fast = fast->next, slow = slow->next);

		ListNode *temp = slow->next;
		slow->next = slow->next->next;
		delete temp;
		return new_head->next;
  }
};

int main() {
  ListNode *list = ListNode::getNewNode(1);
  list->next = ListNode::getNewNode(2);
  list->next->next = ListNode::getNewNode(3);
  list->next->next->next = ListNode::getNewNode(4);
  list->next->next->next->next = ListNode::getNewNode(5);

	Solution s;
  list->displayList();
	list = s.removeNthNodeFromLast(list, 2);
  list->displayList();
}
