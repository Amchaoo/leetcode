#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *swapedHead = NULL;

        if (head -> next) {
            swapedHead = head -> next;
        }
        else {
            return head;
        }
        ListNode *fir = head -> next;
        ListNode *sec = head;
        sec -> next = fir -> next;
        fir -> next = sec;

        while (sec -> next && sec -> next -> next) {
            fir = sec -> next -> next;
            fir -> next = sec -> next;
            sec -> next = fir;
            sec = fir -> next;
        }

        return swapedHead;
    }
};