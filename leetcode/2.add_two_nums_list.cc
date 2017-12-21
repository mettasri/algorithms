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

class Solution {
 public:
  ListNode* addTwoNums(ListNode *l1, ListNode *l2) {
		ListNode head(0);
		ListNode *tail = &head;
		
		int carry = 0;
		while (l1 || l2 || carry) {
			int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			tail->next = ListNode::getNewNode(n % 10);

			tail = tail->next;
			carry = n / 10;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		return head.next;
  }
};

int main() {
  ListNode *list1 = ListNode::getNewNode(1);
  list1->next = ListNode::getNewNode(2);
  list1->next->next = ListNode::getNewNode(3);

  ListNode *list2 = ListNode::getNewNode(4);
  list2->next = ListNode::getNewNode(5);

  list1->displayList();
  list2->displayList();

  Solution s;
  ListNode *list = s.addTwoNums(list1, list2);
	list->displayList();
}
