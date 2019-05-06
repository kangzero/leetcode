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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        
        ListNode* cur = head;
        ListNode* less = dummy1;
        ListNode* more = dummy2;
        
        while (cur != nullptr) {
            if (cur->val < x) {
                less->next = cur;
                less = less->next;
            } else {
                more->next = cur;
                more = more->next;
            }
            cur = cur->next;
        }
        
        more->next = nullptr;
        less->next = dummy2->next;
        ListNode *p = dummy1->next;
        
        delete dummy1;
        dummy1 = nullptr;
        delete dummy2;
        dummy2 = nullptr;
        
        return p;
    }
};
