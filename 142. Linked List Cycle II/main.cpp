#include<iostream>
#include "solution.h"
using namespace std;

ListNode* generateInput() {
    int arr[4] = {1, 2, 3, 4};

    ListNode *head, *tail, *cur;

    for (int i = 0; i < 4; i++) {
        cur->val = arr[i];

        if (!head->next) {
            head = tail = cur;
        }
        else {
            tail->next = cur;
            tail = cur;
        }

        cur = new ListNode;
    }

    return head;
};

int main() {
    Solution s;

    ListNode* result = s.detectCycle(generateInput());
}