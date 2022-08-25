/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode* cur = head;
        std::stack<ListNode*> s;
        while(cur) {
            s.push(cur);
            cur = cur->next;
        }
        cur = head;
        while(cur->next) { 
            ListNode* next = cur->next;
            ListNode* t = s.top();
            s.pop();
            s.top()->next = nullptr;
            cur->next = t;
            if (t == next) {
                break;
            }
            t->next = next;
            cur = next;
        }
    }
};