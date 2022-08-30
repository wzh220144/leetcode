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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<TreeNode *>> t;
    t.resize(2);
    std::vector<std::vector<int32_t>> res;
    if (root) {
      int32_t cur = 0;
      t[cur].emplace_back(root);
      while (!t[cur].empty()) {
        int32_t next = 1 - cur;
        t[next].clear();
        std::vector<int32_t> cur_res;

        for (int32_t i = 0; i < t[cur].size(); ++i) {
          const auto &x = t[cur][i];

          if (x->left) {
            t[next].emplace_back(x->left);
          }
          if (x->right) {
            t[next].emplace_back(x->right);
          }
        }

        if (cur == 0) {
          for (int32_t i = 0; i < t[cur].size(); ++i) {
            const auto &x = t[cur][i];
            cur_res.emplace_back(x->val);
          }
        } else {
          for (int32_t i = t[cur].size() - 1; i >= 0; --i) {
            const auto &x = t[cur][i];
            cur_res.emplace_back(x->val);
          }
        }
        cur = next;
        res.emplace_back(std::move(cur_res));
      }
    }
    return res;
  }
};