/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define RECURSIVE 1
#define ITERATIVE 0
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
#if ITERATIVE
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = head;
        
        while ((pre->next != nullptr) && (pre->next->next != nullptr)) {
            ListNode *tmp = pre->next->next;
            pre->next->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = tmp->next;
        }
        
        ListNode *p = dummy->next;
        delete dummy;
        dummy = nullptr;
        
        return p;
#elif RECURSIVE
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        
        return t;
#endif
    }
};
