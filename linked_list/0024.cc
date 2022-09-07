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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = nullptr;
        if (!head) {
            return res;
        }
        ListNode* pre = nullptr;
        while(head) {
            ListNode* cur = head;
            ListNode* next = head->next;
            if (!next) {
                break;
            }
            ListNode* nnext = next->next;
            if (!res) {
                res = next;
            }
            head = nnext;
            next->next = cur;
            cur->next = head;
            if (pre) {
                pre->next = next;
            }
            pre = cur;
        }
        if (!res) {
            res = head;
        }
        return res;
    }
};