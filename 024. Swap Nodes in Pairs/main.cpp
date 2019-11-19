#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

ListNode* constructLink(vector<int> list) {
    ListNode *head(NULL);

    for (auto val: list) {
        head -> next = new ListNode(val);
    }

    return head -> next;
}

int main() {
    Solution s;

    vector<int> list = {1, 2, 3, 4};
    ListNode *head = constructLink(list);

    while (head) {
        cout << head -> val << endl;
        head = head -> next;
    }
}