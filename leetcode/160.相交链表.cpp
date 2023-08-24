#include "type/type.h"

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = 0;
        int cnt2 = 0;
        auto* p = headA;
        auto* q = headB;

        while (p) {
            p = p->next;
            cnt1++;
        }
        while (q) {
            q = q->next;
            cnt2++;
        }

        auto& i = cnt1 > cnt2 ? headA : headB;
        int cnt = abs(cnt1 - cnt2);
        while (cnt--) {
            i = i->next;
        }

        while (headA) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int state[2] = {0, 1};
        ListNode* next[2] = {headB, headA};

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
            if (!headA && !headB)
                return nullptr;

            if (!headA) {
                headA = next[state[0]];
                state[0] = 1 - state[0];
            }

            if (!headB) {
                headB = next[state[1]];
                state[1] = 1 - state[1];
            }
        }

        return headA;
    }
};
