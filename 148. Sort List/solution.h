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
    ListNode* sortList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* preSlow;

        if (!head || !head -> next) {
            return head;
        }

        while (fast && fast -> next) {
            preSlow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        preSlow -> next = NULL;

        ListNode* l1 = sortList(l1);
        ListNode* l2 = sortList(l2);

        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l, listNode* r) {
        ListNode* main = new ListNode(0), p = l;

        while (l != NULL && r !== NULL) {
            if (l.value <= r.value) {
                p -> next = l;
                l = l -> next;
            }
            else {
                p -> next = r;
                r = r -> next;
            }

            p = p -> next;
            p -> next = NULL;

            if (l == NULL) {
                p -> next = r;
            }
            else if (r == NULL) {
                p -> next = f;
            }
        }

        return main -> next;
    }
};