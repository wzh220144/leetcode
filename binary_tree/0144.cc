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
  void bfs(TreeNode *root, vector<int32_t> &res) {
    if (root == nullptr) {
      return;
    }
    res.emplace_back(root->val);
    bfs(root->left, res);
    bfs(root->right, res);
  }

  void bfs2(TreeNode *root, vector<int32_t> &res) {
    std::stack<TreeNode *> s;
    if (root) {
      s.push(root);
    }
    while (!s.empty()) {
      const auto t = s.top();
      res.emplace_back(t->val);
      s.pop();
      if (t->right) {
        s.push(t->right);
      }
      if (t->left) {
        s.push(t->left);
      }
    }
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int32_t> res;
    bfs2(root, res);
    return res;
  }
};