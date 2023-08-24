#include "type/type.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        while (list1 && list2) {
            auto &l = list1->val < list2->val ? list1 : list2;
            cur->next = l;
            cur = l;
            l = l->next;
        }
        cur->next = list1 ? list1 : list2;

        return dummy->next;
    }
};
