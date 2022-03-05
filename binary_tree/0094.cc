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
    travel(root->left, res);
    res.emplace_back(root->val);
    travel(root->right, res);
  }

  void travel2(TreeNode *root, vector<int32_t> &res) {
    stack<TreeNode *> s;
    auto cur = root;
    while (cur || (!s.empty())) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      res.emplace_back(cur->val);
      cur = cur->right;
    }
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int32_t> res;
    travel(root, res);
    return res;
  }
};