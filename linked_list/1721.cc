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
    ListNode* swapNodes(ListNode* head, int k) {
        int32_t l = 0;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* t = head;
        while(t) {
            ++l;
            if (l == k) {
                a = t;
            }
            t = t->next;
        }
        t = head;
        int32_t ll = 0;
        while(t) {
            if (ll == l - k) {
                b = t;
            }
            ++ll;
            t = t->next;
        }
        int32_t tt = a->val;
        a->val = b->val;
        b->val = tt;
        return head;
    }
};