/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define ITERATIVE_1 0
#define ITERATIVE_2 1
#define RECURSIVE 0

class Solution {
public:
#if ITERATIVE_1
    ListNode* reverseKGroup(ListNode* head, int k) {
        if ((head == NULL) || (k == 1)) return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        ListNode *cur = head;
        dummy->next = head;
        
        for (int i = 1; (cur != NULL); i++) {
            if (i % k == 0) {
                pre = reverseList(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
    
    ListNode *reverseList(ListNode* pre, ListNode* next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
#elif ITERATIVE_2
    ListNode* reverseKGroup(ListNode* head, int k) {
        if ((head == NULL) || (k == 1)) return head;
            
        ListNode *cur = head;
        int len = 0;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        dummy->next = head;
        while (len >= k) {
            cur = prev->next;
            for (int i = 1; i < k; i++) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            }
            prev = cur;
            len -= k;
        }
        
        return dummy->next;
    }
#elif RECURSIVE
    //implement later...
    
#endif
};
