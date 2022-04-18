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

    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root->left) {
            if (root->left->val >= root->val) {
                return false;
            }
            if (min && root->left->val <= min->val) {
                return false;
            }
            if (max && root->left->val >= max->val) {
                return false;
            }
            if (!isValid(root->left, min, root)) {
                return false;
            }
        }
        if (root->right) {
            if (root->right->val <= root->val) {
                return false;
            }
            if (min && root->right->val <= min->val) {
                return false;
            }
            if (max && root->right->val >= max->val) {
                return false;
            }
            if (!isValid(root->right, root, max)) {
                return false;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};