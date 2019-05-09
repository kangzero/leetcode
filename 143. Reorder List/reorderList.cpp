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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        
        ListNode *p1 = head;
        ListNode *t = middleNode(head);
        ListNode *halfhead = t->next;
        t->next = nullptr;
        cout << halfhead->val << endl;
        
        
        ListNode *p2 = reverseList(halfhead);
        
        while ((p1 != nullptr) && (p2 != nullptr)) {
            ListNode *tmp1 = p1->next;
            ListNode *tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while((fast != nullptr) && (fast->next != nullptr)) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        ListNode *cur = head;
        ListNode *pre = nullptr;
        
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};
