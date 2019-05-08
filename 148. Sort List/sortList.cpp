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
    ListNode* sortList(ListNode* head) {
        if((head == nullptr) || head->next == nullptr) return head;
        
        ListNode* s1 = head;
        ListNode* s2 = head;
        ListNode* f = head;
        
        while ((f != nullptr) && (f->next != nullptr)) {
            s1 = s2;
            s2 = s2->next;
            f = f->next->next;
            //cout << s1->val << " " << s2->val << endl;
        }
        s1->next = nullptr; //split to 2 linkedlist
        return merge(sortList(head), sortList(s2));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
