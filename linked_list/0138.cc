/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* cur = head;
        while(cur != nullptr) {
            Node* n = new Node(cur->val);
            n->random = cur->random;
            n->next = cur->next;
            cur->next = n;
            cur = n->next;
        }
        cur = head;
        Node* res = nullptr;
        while(cur != nullptr) {
            if (res == nullptr) {
                res = cur->next;
            }
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        while(cur != nullptr) {
            Node* a1 = cur->next;
            Node* a2 = cur->next->next;
            Node* a3 = nullptr;
            if (a2 != nullptr) {
                a3 = a2->next;
            }
            cur->next = a2;
            a1->next = a3;
            cur = a2;
        }
        return res;
    }
};