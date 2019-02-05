#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pos = NULL;
        ListNode* head = NULL;
        int carry = 0;
        int p1, p2;
        while (l1 != NULL or l2 != NULL or carry > 0) {
            if (pos == NULL) {
                head = pos = new ListNode(0);
            } else {
                pos = pos->next = new ListNode(0);
            }
            if (l1) {
                p1 = l1->val;
                l1 = l1->next;
            } else
                p1 = 0;
            if (l2) {
                p2 = l2->val;
                l2 = l2->next;
            } else
                p2 = 0;
            pos->val = p1 + p2 + carry;
            if (pos->val >= 10) {
                carry = 1;
                pos->val -= 10;
            } else
                carry = 0;
        }
        return head;
    }
};
int main(int argc, char const* argv[]) {
    ListNode a1 = ListNode(1);
    ListNode a2 = ListNode(3);
    a1.next = &a2;
    ListNode a3 = ListNode(4);
    a2.next = &a3;

    ListNode b1 = ListNode(9);
    ListNode b2 = ListNode(3);
    b1.next = &b2;
    ListNode b3 = ListNode(6);
    b2.next = &b3;
    ListNode* res = Solution().addTwoNumbers(&a1, &b1);
    ListNode* tmp;
    while (res) {
        cout << res->val;
        tmp = res;
        res = res->next;
        free(tmp);
    }
    return 0;
}
