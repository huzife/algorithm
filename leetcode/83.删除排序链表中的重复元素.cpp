#include "type/type.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto* slow = head;
        auto* fast = head;
        while (fast) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
