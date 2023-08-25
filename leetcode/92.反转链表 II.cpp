#include "type/type.h"

// 迭代
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto* dum = new ListNode(0, head);
        auto* l = dum;
        for (int i = 1; i < left; i++) {
            l = l->next;
        }

        auto* last = l;
        auto* p = l->next;
        int n = right - left + 1;
        while (n--) {
            auto* next = p->next;
            p->next = last;
            last = p;
            p = next;
        }

        l->next->next = p;
        l->next = last;

        return dum->next;
    }
};

// 递归
class Solution2 {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		auto* dum = new ListNode(0, head);
		auto* p = dum;
		for (int i = 1; i < left; i++) {
			p = p->next;
		}

		p->next = reverseN(p->next, right - left + 1);
		return dum->next;
	}

	ListNode* reverseN(ListNode* head, int n) {
		if (n == 1)
			return head;

		auto* last = reverseN(head->next, n - 1);
		auto* next = head->next->next;
		head->next->next = head;
		head->next = next;
		return last;
	}
};
