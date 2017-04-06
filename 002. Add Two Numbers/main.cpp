#include "solution.h";

void main() {
    Solution s;

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *p = s.addTwoNumbers(l1, l2);
}