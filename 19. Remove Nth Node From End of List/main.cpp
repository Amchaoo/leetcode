#include <iostream>
#include "solution.h"
using namespace std;

ListNode* create(int n) {
    ListNode* head = new ListNode(0);
    ListNode* prev = head;
    for (int i = 1; i < n; i++) {
        prev->next = new ListNode(i);
        prev = prev->next;
    }

    return head;
}

void printList(ListNode* head, string title) {
    cout << title;
    while (head != NULL) {
        cout << head->val;
        head = head -> next;

        if (head) {
            cout << "-->";
        }
        else {
            cout << endl;
        }
    }
}

int main() {
	Solution s;

    ListNode* input = create(6);
    printList(input, "input");
    ListNode* result = s.removeNthFromEnd(input, 3);
    printList(result, "output");

    return 0;
}