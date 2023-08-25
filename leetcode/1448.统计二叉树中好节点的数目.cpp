#include "type/type.h"

class Solution {
public:
    int good_count = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, 0x80000000);
        return good_count;
    }

    void dfs(TreeNode* root, int max) {
        if (!root)
            return;

        if (root->val >= max) {
            max = root->val;
            good_count++;
        }

        dfs(root->left, max);
        dfs(root->right, max);
    }
};