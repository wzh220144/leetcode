/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  pair<int32_t, bool> travel(TreeNode *root) {
    if (root->left && root->right) {
      auto l = travel(root->left);
      auto r = travel(root->right);
      int32_t c = 0;
      bool s = false;
      if (l.second && r.second) {
        if (root->left->val == root->right->val &&
            root->left->val == root->val) {
          c = 1;
          s = true;
        }
      }
      return pair<int32_t, bool>(l.first + r.first + c, s);
    } else if (root->left) {
      auto l = travel(root->left);
      int32_t c = 0;
      bool s = false;
      if (l.second && root->left->val == root->val) {
        c = 1;
        s = true;
      }
      return pair<int32_t, bool>(l.first + c, s);
    } else if (root->right) {
      auto r = travel(root->right);
      int32_t c = 0;
      bool s = false;
      if (r.second && root->right->val == root->val) {
        c = 1;
        s = true;
      }
      return pair<int32_t, bool>(r.first + c, s);
    } else {
      return pair<int32_t, bool>(1, true);
    }
  }

  int countUnivalSubtrees(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto res = travel(root);
    return res.first;
  }
};