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
class BSTIterator {
public:
    std::stack<TreeNode*> s;
    TreeNode* cur = nullptr;

    void travel() {
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        if (s.empty()) {
            cur = nullptr;
        } else {
            cur = s.top();
        }
    }

    BSTIterator(TreeNode* root) {
        cur = root;
        travel();
    }
    
    int next() {
        int32_t res = cur->val;
        s.pop();
        cur = cur->right;
        travel();
        return res;
    }
    
    bool hasNext() {
        return cur != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */