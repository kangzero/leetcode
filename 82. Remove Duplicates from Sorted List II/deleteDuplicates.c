/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *cur = head;
    struct ListNode *tail = dummy;
    
    while ((cur != NULL) && (cur->next != NULL)) {
        if (cur->val != cur->next->val) {
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
        } else {
            while ((cur->next != NULL) && (cur->val == cur->next->val)) {
                struct ListNode *tmp = cur;
                cur = cur->next;
                free(tmp);
                tmp = NULL;
            }
            cur = cur->next; //delete all the duplicate numbers; remove this if need to keep one
        }
    }
    tail->next = cur;
        
    struct ListNode *p = dummy->next;
    free(dummy);
    dummy = NULL;
    
    return p; 
}

