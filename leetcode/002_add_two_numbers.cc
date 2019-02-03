#include <stdlib.h>

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
