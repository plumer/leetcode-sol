#include <iostream>

using std::cout;

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL;
        ListNode ** nextNode = &head;
        int carry = 0, currentDigit = 0;
        while (l1 && l2) {
            currentDigit = carry + l1 -> val + l2 -> val;
            // changed the following 2 lines to boost efficiency
            carry = currentDigit >= 10;
            if (carry) currentDigit -= 10;

            *nextNode = new ListNode(currentDigit);
            l1 = l1 -> next;
            l2 = l2 -> next;
            nextNode = &( (*nextNode) -> next );
        }

        ListNode * remain = l1;
        if (!remain) remain = l2;
        while (remain) {
            currentDigit = carry + remain -> val;
            carry = currentDigit >= 10;
            if (carry) currentDigit -= 10;
            *nextNode = new ListNode(currentDigit);
            remain = remain -> next;
            nextNode = &( (*nextNode) -> next );
        }

        if (carry == 1)
            *nextNode = new ListNode(1);

        return head;
    }
};

void print(ListNode * l) {
    cout << '(';
    while (l) {
        cout << l -> val << " -> ";
        l = l -> next;
    }
    cout << ')';
}

int main() {
    ListNode * l1 = new ListNode(0);
    //l1 -> next = new ListNode(4);
    //l1 -> next -> next = new ListNode(6);

    ListNode * l2 = new ListNode(0);
    //l2 -> next = new ListNode(6);
    //l2 -> next -> next = new ListNode(4);
    //l2 -> next -> next -> next = new ListNode(3);

    print(l1);
    cout << '\n';
    print(l2);
    cout << '\n';

    Solution sol;
    ListNode * res = sol.addTwoNumbers(l1, l2);
    print(res);

    return 0;
}
