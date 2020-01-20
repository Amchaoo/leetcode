/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curPoint = head;
        ListNode* tail = NULL;
        int len = 0;

        while (curPoint) {
            len++;
            tail = curPoint;
            curPoint = curPoint -> next;
        }

        if (len == 0) {
            return head;
        }

        k = k % len;

        if (k == 0) {
            return head;
        }

        int index = 0;
        ListNode* newHead = head;
        ListNode* newTail = null;
        while(index < (len - k)) {
            newTail = newHead;
            newHead = newHead -> next;
        }
        tail -> next = head;
    }
};