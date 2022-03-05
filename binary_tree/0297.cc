/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    std::vector<std::string> strSplit(const std::string& str, char delim) {
        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim)) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }
        return elems;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> v;
        queue<TreeNode*> q;
        if (root) {
            v.emplace_back(to_string(root->val));
            q.push(root);
        }
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                v.emplace_back(to_string(cur->left));
                q.push(cur->left);
            } else {
                v.emplace_back("");
            }
            if (cur->right) {
                v.emplace_back(to_string(cur->right));
                q.push(cur->right);
            } else {
                v.emplace_back("");
            }
        }
        string res = "";
        for (int32_t i = 0; i < v.size(); ++i) {
            if (i != v.size() - 1) {
                res += ",";
            }
            res += v[i];
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = null;
        if (data.size() > 0) {

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));