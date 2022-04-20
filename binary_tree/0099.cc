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

    void inorder(TreeNode* root, std::vector<TreeNode*>& list) {
        if (root->left) {
            inorder(root->left, list);
        }
        list.emplace_back(root);
        if (root->right) {
            inorder(root->right, list);
        }
    }

    void recoverTree(TreeNode* root) {
        std::vector<TreeNode*> list;
        inorder(root, list);
        TreeNode* l = nullptr;
        TreeNode* r = nullptr;
        for (size_t i = 0; i < list.size() - 1; ++i) {
            TreeNode* a = list[i];
            TreeNode* b = list[i + 1];
            if (a->val > b->val) {
                if (!l) {
                    l = a;
                }
                r = b;
            }
        }
        int32_t t = l->val;
        l->val = r->val;
        r->val = t;
    }
};