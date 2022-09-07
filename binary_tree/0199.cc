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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int32_t> res;
        vector<std::queue<TreeNode*>> qs;
        qs.resize(2);
        if (!root)
        {
            return res;
        }
        int32_t cur = 0;
        qs[cur].push(root);
        while(!qs[cur].empty()) {
            int32_t next = 1 - cur;
            TreeNode* last = nullptr;
            while(!qs[cur].empty()) {
                auto& t = qs[cur].front();
                qs[cur].pop();
                last = t;
                if (t->left) {
                    qs[next].push(t->left);
                }
                if (t->right) {
                    qs[next].push(t->right);
                }
            }
            if (last) {
                res.emplace_back(last->val);
            }
            cur = next;
        }
        return res;
    }
};