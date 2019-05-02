/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur  = dummy;
        ListNode *p = l1;
        ListNode *q = l2;
        int c = 0;
        
        while ((p != NULL) || (q != NULL) || (c != 0)) {
            int x = (p == NULL) ? 0 : p->val;
            int y = (q == NULL) ? 0 : q->val;
            int s = x + y + c;
            
            c = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
            
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        
        return dummy->next;
    }
};
