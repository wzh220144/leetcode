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
        TreeNode* root = nullptr;
        if (data.size() > 0) {
            auto v = strSplit(data, ",");
            int32_t i = 0;
            root = new TreeNode();
            root->val = stoi(v[i]);
            ++i;
            queue<TreeNode*> q;
            q.push(root);
            q.push(root);
            while(i < v.size()) {
                auto cur = q.front();
                q.pop();
                if (v[i].size() != 0) {
                    TreeNode* t = new TreeNode();
                    t->val = stoi(v[i]);
                    ++i;
                    cur.left = t;
                    q.push(t);
                }
                cur = q.front();
                q.pop();
                if (v[i].size() != 0) {
                    TreeNode* t = new TreeNode();
                    t->val = stoi(v[i]);
                    ++i;
                    cur.right = t;
                    q.push(t);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root))/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>

class Codec {
public:

    std::vector<std::string> strSplit(const std::string& str, char delim) {
        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        if (str[str.size() - 1] == delim) {
            elems.push_back("");
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
                v.emplace_back(to_string(cur->left->val));
                q.push(cur->left);
            } else {
                v.emplace_back("");
            }
            if (cur->right) {
                v.emplace_back(to_string(cur->right->val));
                q.push(cur->right);
            } else {
                v.emplace_back("");
            }
        }
        string res = "";
        for (int32_t i = 0; i < v.size(); ++i) {
            if (i != 0) {
                res += ",";
            }
            res += v[i];
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if (data.size() > 0) {
            auto v = strSplit(data, ',');
            int32_t i = 0;
            root = new TreeNode();
            root->val = stoi(v[i]);
            ++i;
            queue<TreeNode*> q;
            q.push(root);
            q.push(root);
            while(i < v.size()) {
                auto cur = q.front();
                q.pop();
                if (v[i].size() != 0) {
                    TreeNode* t = new TreeNode();
                    t->val = stoi(v[i]);
                    cur->left = t;
                    q.push(t);
                    q.push(t);
                }
                ++i;
                cur = q.front();
                q.pop();
                if (v[i].size() != 0) {
                    TreeNode* t = new TreeNode();
                    t->val = stoi(v[i]);
                    cur->right = t;
                    q.push(t);
                    q.push(t);
                }
                ++i;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));;