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
  void travel(TreeNode *root, vector<int32_t> &res) {
    if (!root) {
      return;
    }
    if (root->left) {
      travel(root->left, res);
    }
    if (root->right) {
      travel(root->right, res);
    }
    res.emplace_back(root->val);
  }

  void travel2(TreeNode *root, vector<int32_t> &res) {
    stack<TreeNode *> s;
    TreeNode *last = NULL;
    while (root || !s.empty()) {
      if (root) {
        s.push(root);
        root = root->left;
      } else {
        TreeNode *node = s.top();
        if (node->right && last != node->right) {
          root = node->right;
        } else {
          res.push_back(node->val);
          last = node;
          s.pop();
        }
      }
    }
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int32_t> res;
    travel2(root, res);
    return res;
  }
};