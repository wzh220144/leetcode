/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    std::vector<std::vector<Node *>> vs;
    std::vector<Node *> v1;
    std::vector<Node *> v2;
    vs.emplace_back(std::move(v1));
    vs.emplace_back(std::move(v2));
    int32_t cur = 0;
    if (root) {
      vs[cur].emplace_back(root);
    }
    while (!vs[cur].empty()) {
      int32_t next = 1 - cur;
      Node *pre = nullptr;
      for (auto x : vs[cur]) {
        if (pre != nullptr) {
          pre->next = x;
        }
        pre = x;
        if (x->left) {
          vs[next].emplace_back(x->left);
        }
        if (x->right) {
          vs[next].emplace_back(x->right);
        }
      }
      cur = next;
    }
  }
};