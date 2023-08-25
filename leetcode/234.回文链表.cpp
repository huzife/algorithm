#include "type/type.h"

class Solution {
public:
    ListNode* left;

    bool isPalindrome(ListNode* head) {
        left = head;
        return check(head);
    }

    bool check(ListNode* right) {
        if (!right)
            return true;

        bool ret = check(right->next);
        ret &= (left->val == right->val);
        left = left->next;
        return ret;
    }
};
