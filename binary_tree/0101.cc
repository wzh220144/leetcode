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
  bool isSame(TreeNode *left, TreeNode *right) {
    if ((!left) && (!right)) {
      return true;
    } else if (!left) {
      return false;
    } else if (!right) {
      return false;
    } else {
      if (left->val != right->val) {
        return false;
      }
      return isSame(left->left, right->right) &&
             isSame(left->right, right->left);
    }
  }

  bool isSymmetric(TreeNode *root) {
    if (root) {
      return isSame(root->left, root->right);
    } else {
      return true;
    }
  }
};