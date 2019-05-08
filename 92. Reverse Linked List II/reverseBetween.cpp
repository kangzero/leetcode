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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        ListNode *rev_m = nullptr;
        ListNode *rev_n = nullptr;
        ListNode *rev_m_prev = nullptr;
        ListNode *rev_n_next = nullptr;
        ListNode *cur = head;
        int cnt = 1;
        while ((cur != nullptr) && (cnt <= n)) {
            if (cnt < m) {
                rev_m_prev = cur;
            }
            if (cnt == m) {
                rev_m = cur;
            }
            if (cnt == n) {
                rev_n = cur;
                rev_n_next = cur->next;
            }
            cur = cur->next;
            cnt++;
        }
        rev_n->next = nullptr;
        rev_n = reverselist(rev_m);
        if (rev_m_prev != nullptr) {
            rev_m_prev->next = rev_n;
        } else {
            head = rev_n;
        }
        rev_m->next = rev_n_next;
        
        return head;
    }
    
    ListNode* reverselist(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
