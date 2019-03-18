/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL 0;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (
            fast->next
            && fast->next->next
            && slow->next
        ) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                while (head != slow) {
                    head = head -> next;
                    slow = slow -> next;
                }

                return head;
            }
        }

        return NULL;
    }
};