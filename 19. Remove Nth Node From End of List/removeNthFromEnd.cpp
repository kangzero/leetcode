/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define TWICE_PASS 0 
#define ONE_PASS 1

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
#if TWICE_PASS
        int len = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        cout << len << endl;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        cur = dummy;
        for (int i = 0; i < (len-n); i++) {
            cur = cur->next;
        }
        
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = NULL;
        
        ListNode *ret = dummy->next;
        delete dummy;
        dummy = NULL;
        
        return ret;
#elif ONE_PASS
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (p1 != NULL) {
            p1 = p1->next;
            if (n-- < 0) {
                p2 = p2->next;
            }
        }
        
        ListNode *tmp = p2->next;
        if (n == 0) {
            tmp = head;
            head = head->next;
        } else {
            p2->next = p2->next->next;
        }
        
        delete tmp;
        tmp = NULL;
        
        return head;
#endif
    }
};
