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
  class Compare {
  public:
    bool operator()(const ListNode *a, const ListNode *b) const {
      return a->val < b->val;
    }
  };

  ListNode *merge(std::multiset<ListNode *, Compare> &s) {
    ListNode *cur = *s.begin();
    s.erase(s.begin());
    ListNode *next = cur->next;
    if (next) {
      s.insert(next);
    }
    return cur;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    std::multiset<ListNode *, Compare> s;
    for (const auto &list : lists) {
      if (list) {
        s.insert(list);
      }
    }
    ListNode *pre = nullptr;
    while (!s.empty()) {
      ListNode *cur = merge(s);
      if (!head) {
        head = cur;
      }
      if (pre) {
        pre->next = cur;
      }
      pre = cur;
    }
    return head;
  }
};