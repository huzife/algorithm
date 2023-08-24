#include "type/type.h"

class ListNodeCmp {
public:
    bool operator()(const ListNode* l1, const ListNode* l2) const {
        return l1->val >= l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto* dummy = new ListNode;
        auto* cur = dummy;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> q;

        for (auto i : lists) {
            if (i)
                q.push(i);
        }

        while (!q.empty()) {
            auto next = q.top();
            q.pop();
            cur->next = next;
            cur = next;
            if (next->next) {
                q.push(next->next);
            }
        }

        return dummy->next;
    }
};
