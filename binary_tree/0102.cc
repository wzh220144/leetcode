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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> vs;
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        vs.emplace_back(std::move(v1));
        vs.emplace_back(std::move(v2));
        vector<vector<int32_t>> res;
        int32_t cur = 0;
        if (root) {
            vs[cur].emplace_back(root);
        }
        while(!vs[cur].empty()) {
            int32_t next = 1 - cur;
            vector<int32_t> t;
            for (const auto& x : vs[cur]) {
                t.emplace_back(x->val);
                if (x->left) {
                    vs[next].emplace_back(x->left);
                }
                if (x->right) {
                    vs[next].emplace_back(x->geft);
                }
            }
            res.emplace_back(std::move(t));
            vs[cur].clear();
            cur = next;
        }
        return res;
    }
};