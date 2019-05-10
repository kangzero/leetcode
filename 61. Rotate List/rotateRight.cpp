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
    ListNode* rotateRight(ListNode* head, int k) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        int cnt = 1;
        ListNode *link = head;
        ListNode *tail = head;
        while (link->next != nullptr) {
            cnt++;
            link = link->next;
        }
        k %= cnt;
        
        if (k == 0) return head;
        
        for (int i = 1; i < (cnt - k); i++) {
             tail = tail->next;
        }
        ListNode *newhead = tail->next;
        link->next = head;
        tail->next = nullptr;
        
        return newhead;    
    }
};
