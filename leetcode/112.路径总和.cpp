/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }

    bool check(TreeNode* root, int targetSum, int sum) {
        if (!root)
            return false;

        int new_sum = root->val + sum;
        if (new_sum > targetSum)
            return false;

        if (new_sum == targetSum && !root->left && !root->right)
            return true;

        return (root->left && check(root->left, targetSum, new_sum)) || (root->right && check(root->right, targetSum, new_sum));
    }
};
// @lc code=end
