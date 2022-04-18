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
 */
class Solution {
public:

    int32_t find(TreeNode* root, int32_t& k) {
        if (root->left) {
            int32_t res = find(root->left, k);
            if (k == 0) {
                return res;
            }
        }
        --k;
        if (k == 0) {
            return root->val;
        }
        if (root->right) {
            int32_t res = find(root->right, k);
            if (k == 0) {
                return res;
            }
        }
        return root->val;
    }

    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};