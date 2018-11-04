#include <iostream>
using namespace std;

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = new ListNode(0);
        ListNode* lastNode = mergedList;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                lastNode->next = l1;
                l1 = l1->next;
            }
            else {
                lastNode->next = l2;
                l2 = l2->next;
            }

            lastNode = lastNode->next;
        }

        lastNode->next = l1 ? l1 : l2;

        return mergedList->next;
    }
};