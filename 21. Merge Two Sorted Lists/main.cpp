#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

ListNode* create(vector<int>& input) {
    ListNode* head = new ListNode(input[0]);
    ListNode* prev = head;
    for (int i = 1; i < input.size(); i++) {
        prev->next = new ListNode(input[i]);
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

    vector<int> vals1 = {1, 2, 4};
    vector<int> vals2 = {1, 3, 4};

    ListNode* input1 = create(vals1);
    ListNode* input2 = create(vals2);

    printList(input1, "list one");
    printList(input2, "list two");

    ListNode* result = s.mergeTwoLists(input1, input2);

    printList(result, "merged list");
    return 0;
}