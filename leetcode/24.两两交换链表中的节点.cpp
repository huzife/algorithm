/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		auto* vhead = new ListNode(0, head);
		auto* p = vhead;
		while (p->next) {
			auto* first = p->next;
			if (!first->next)
				break;

            auto* second = first->next;
            p->next = second;
            first->next = second->next;
            second->next = first;
            p = first;
		}

        return vhead->next;
	}
};
// @lc code=end
