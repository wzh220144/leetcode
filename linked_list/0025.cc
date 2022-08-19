/**
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/
class Solution {
public:
    void reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            head;
        }
        ListNode* new_head = nullptr;
        ListNode* start = nullptr;
        ListNode* last = nullptr;
        ListNode* pre = nullptr;
        int32_t cnt = 0;
        while (head) {
            if (!start) {
                start = head;
            }
            last = head;
            head = head->next;
            ++cnt;
            if (cnt == k) {
                ListNode* tmp = last->next;
                last->next = nullptr;
                reverse(start);
                start->next = tmp;
                if (!pre) {
                    new_head = last;
                } else {
                    pre->next = last;
                }
                pre = start;
                // 清空临时变量
                cnt = 0;
                last = nullptr;
                start = nullptr;
            }
        }
        return new_head;
    }
};