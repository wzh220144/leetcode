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
  std::map<int32_t, int32_t> m1;
  std::map<int32_t, int32_t> m2;
  int32_t cur;

  void doBuildTree(TreeNode *root, vector<int> &preorder, vector<int> &inorder,
                   int32_t left, int32_t right) {
    if (left == right) {
      return;
    }
    int32_t root_index = m2[root->val];
    if (root_index > left) {
      TreeNode *next = new TreeNode();
      root->left = next;
      next->val = preorder[cur];
      ++cur;
      doBuildTree(next, preorder, inorder, left, root_index - 1);
    }

    if (root_index < right) {
      TreeNode *next = new TreeNode();
      root->right = next;
      next->val = preorder[cur];
      ++cur;
      doBuildTree(next, preorder, inorder, root_index + 1, right);
    }
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int32_t i = 0; i < preorder.size(); ++i) {
      m1[preorder[i]] = i;
    }
    for (int32_t i = 0; i < inorder.size(); ++i) {
      m2[inorder[i]] = i;
    }
    if (preorder.size() > 0) {
      TreeNode *root = new TreeNode();
      cur = 0;
      root->val = preorder[cur];
      ++cur;
      doBuildTree(root, preorder, inorder, 0, inorder.size() - 1);
      return root;
    } else {
      return nullptr;
    }
  }
};