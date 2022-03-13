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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        int32_t n = 0;
        ListNode* res = nullptr;
        ListNode* cur = head;
        ListNode* pre = head;
        while(cur) {
            ++n;
            if (cur->next == nullptr) {
                cur->next = head;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        k = n - k % n;
        int32_t cnt = 0;
        cur = head;
        while(true) {
            if (cnt == k) {
                pre->next = nullptr;
                res = cur;
                break;
            }
            pre = cur;
            cur = cur->next;
            ++cnt;
        }
        return res;
    }
};