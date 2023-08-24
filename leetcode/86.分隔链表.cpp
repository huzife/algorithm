#include "type/type.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto* dum_lt = new ListNode;
        auto* dum_ge = new ListNode;
        auto* p = dum_lt;
        auto* q = dum_ge;

        while (head) {
            auto& cur = head->val < x ? p : q;
            cur->next = head;
            cur = head;
            head = head->next;
            cur->next = nullptr;
        }

        p->next = dum_ge->next;
        return dum_lt->next;
    }
};
