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
    Node *leftmost = root;
    while (leftmost) {
      Node *cur = leftmost;
      leftmost = nullptr;
      Node *pre = nullptr;
      while (cur) {
        if (cur->left) {
          if (pre) {
            pre->next = cur->left;
          } else {
            leftmost = cur->left;
          }
          pre = cur->left;
        }
        if (cur->right) {
          if (pre) {
            pre->next = cur->right;
          } else {
            leftmost = cur->right;
          }
          pre = cur->right;
        }
        cur = cur->next;
      }
    }
    return root;
  }
};