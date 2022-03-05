/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q, bool& has) {
        TreeNode* t1 = nullptr;
        TreeNode* t2 = nullptr;
        if (root->left) {
            t1 = find(root->left, p, q, has);
            if (has) {
                return t1;
            }
        }
        if (root->right) {
            t2 = find(root->right, p, q, has);
            if (has) {
                return t2;
            }
        }
        bool left = false;
        bool right = false;
        bool hit = false;
        if (t1 == p || t1 == q) {
            left = true;
        }
        if (t2 == p || t2 == q) {
            right = true;
        }
        if (root == p || root == q) {
            hit = true;
        }
        if (left && right) {
            has = true;
            return root;
        }
        if (hit && (left || right)) {
            has = true;
            return root;
        }
        if (left) {
            return t1;
        }
        if (right) {
            return t2;
        }
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            bool has = false;
            return find(root, p, q, has);
        } else {
            return nullptr;
        }
    }
};