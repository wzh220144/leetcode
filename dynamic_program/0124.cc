/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 * 路径和 是路径中各节点值的总和。
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/binary-tree-maximum-path-sum
 */
class Solution {
public:
    int32_t dfs(TreeNode* root, int32_t& max) {
        if (root == nullptr) {
            return 0;
        }
        int32_t left = dfs(root->left, max);
        int32_t right = dfs(root->right, max);
        int32_t left_mid = left + root->val;
        int32_t right_mid = right + root->val;
        int32_t all = left + right + root->val;
        max = std::max(max, left_mid);
        max = std::max(max, right_mid);
        max = std::max(max, all);
        max = std::max(max, root->val);
        int32_t cur_max = root->val;
        cur_max = std::max(cur_max, left_mid);
        cur_max = std::max(cur_max, right_mid);
        return cur_max;
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int32_t res = root->val;
        dfs(root, res);
        return res;
    }
};