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
    ListNode* middleNode(ListNode* head) {
        ListNode *f = head;
        ListNode *s = head;
        
        while (f != NULL && f->next != NULL) {
            f = f->next->next;
            s = s->next;
        }
        
        return s;
    }
};
