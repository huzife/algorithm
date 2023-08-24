#include "type/type.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto* l = head;
        auto* r = head;
        while (r && r->next) {
            l = l->next;
            r = l->next;
        }

        return l;
    }
};
