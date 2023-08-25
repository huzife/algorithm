#include "type/type.h"

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        while (head) {
            auto* next = head->next;
            head->next = last;
            last = head;
            head = next;
        }

        return last;
    }
};

// 递归解法
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        auto* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
