#include "type/type.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* dum = new ListNode(0, head);
        auto* new_head = reverseN(head, k);
        auto* left = dum;
        while (new_head) {
            left->next = new_head;
            left = head;
            head = head->next;
            new_head = reverseN(head, k);
        }

        return dum->next;
    }

    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1)
            return head;

        if (!head)
            return nullptr;

        auto* last = reverseN(head->next, n - 1);
        if (!last)
            return nullptr;

        auto* next = head->next->next;
        head->next->next = head;
        head->next = next;
        return last;
    }
};
