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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ( (!l1) && (!l2) ) {
            return nullptr;
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int32_t add = 0;
        while(true) {
            if ( (!l1) && (!l2) ) {
                break;
            }
            int32_t t = add;
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            cur->val = t % 10;
            add = t / 10;
            if ( (!l1) && (!l2) ) {
                break;
            }
            cur->next = new ListNode();
            cur = cur->next;
        }
        if (add > 0) {
            cur->next = new ListNode(add);
        }
        return head;
    }
};