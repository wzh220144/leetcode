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
    std::map<int32_t, int32_t> m1;
    std::map<int32_t, int32_t> m2;
    int32_t cur;

    void doBuildTree(TreeNode* root, vector<int>& inorder, vector<int>& postorder, int32_t left, int32_t right) {
        if (left == right) {
            return;
        }
        int32_t root_index = m1[root->val];
        if (root_index < right) {
            TreeNode* next = new TreeNode();
            root->right = next;
            next->val = postorder[cur];
            --cur;
            doBuildTree(next, inorder, postorder, root_index + 1, right);
        }
        if (root_index > left) {
            TreeNode* next = new TreeNode();
            root->left = next;
            next->val = postorder[cur];
            --cur;
            doBuildTree(next, inorder, postorder, left, root_index - 1);
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int32_t i = 0; i < inorder.size(); ++i) {
            m1[inorder[i]] = i;
        }
        for (int32_t i = 0; i < postorder.size(); ++i) {
            m2[postorder[i]] = i;
        }
        if (postorder.size() > 0) {
            TreeNode* root = new TreeNode();
            cur = postorder.size() - 1;
            root->val = postorder[cur];
            --cur;
            doBuildTree(root, inorder, postorder, 0, inorder.size() - 1);
            return root;
        } else {
            return nullptr;
        }
    }
};