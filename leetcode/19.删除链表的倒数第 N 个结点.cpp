#include "type/type.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* dum = new ListNode(0, head);
        auto* l = dum;
        auto* r = dum;

        while (n--) {
            r = r->next;
        }

        while (r->next) {
            l = l->next;
            r = r->next;
        }

        l->next = l->next->next;
        return dum->next;
    }
};
