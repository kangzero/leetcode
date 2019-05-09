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
    ListNode* deleteDuplicates(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        ListNode *cur = head;
        ListNode *dummyhead = new ListNode(0);
        ListNode *tail = dummyhead;
        
        while ((cur != nullptr) && (cur->next != nullptr)) {
            if (cur->val != cur->next->val) {
                tail->next = cur;
                tail = tail->next;
                cur = cur->next;
            } else {
                while ((cur->next != nullptr) && (cur->val == cur->next->val)) {
                    ListNode *tmp = cur;
                    //printf("tmp->val = %d\n", tmp->val);
                    cur = cur->next;
                    delete tmp;
                }
                ListNode *tmp = cur;
                //printf("tmp->val = %d\n", tmp->val);
                cur = cur->next;
                delete tmp;
            }
        }
        tail->next = cur;
        
        return dummyhead->next;
    }
};
