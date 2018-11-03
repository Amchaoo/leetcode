using namespace std;
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // now n is equal to the listnode's length
        // just remove the head
        if (fast == NULL) {
            return head->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // when n is 0,  slow->next == NULL
        if (slow->next != NULL) {
            slow->next = slow->next->next;
        }

        return head;
    }
};