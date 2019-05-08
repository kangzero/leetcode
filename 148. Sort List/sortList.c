/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeSort(struct ListNode *p1, struct ListNode *p2);

struct ListNode* sortList(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *p = slow;
    
    while ((fast != NULL) && (fast->next != NULL)) {
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    p->next = NULL;
    
    return mergeSort(sortList(head), sortList(slow));
}

struct ListNode* mergeSort(struct ListNode *p1, struct ListNode *p2) {
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    
    while ((p1 != NULL) && (p2 != NULL)) {
        if (p1->val <= p2->val) {
            cur->next = p1;
            p1 = p1->next;
        } else {
            cur->next = p2;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    
    if (p1 != NULL) {
        cur->next = p1;
    } 
    
    if (p2 != NULL) {
        cur->next = p2;
    }
    
    struct ListNode *p = dummy->next;
    free(dummy);
    dummy = NULL;
    
    return p;
}
