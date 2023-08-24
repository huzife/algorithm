#include "type/type.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto* fast = head;
        while (fast && fast->next) {
            head = head->next;
            fast = fast->next->next;
            if (head == fast)
                return true;
        }

        return false;
    }
};
