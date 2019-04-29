/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define RECURSIVE 0
#define ITERATIVE 1

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
#if RECURSIVE
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return p;
#elif ITERATIVE
        ListNode *cur = head;
        ListNode *pre = nullptr;
        
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
#endif
    }
};
