/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define ITERATIVE 0
#define RECURSIVE 1

struct ListNode* swapPairs(struct ListNode* head){
#if ITERATIVE
    if ((head == NULL) || (head->next) == NULL) return head;
    
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *pre = dummy;
    
    while ((pre->next != NULL) && (pre->next->next != NULL)) {
        struct ListNode *tmp = pre->next->next;
        pre->next->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
        pre = tmp->next;
    }
    
    struct ListNode *ret = dummy->next;
    free(dummy);
    dummy = NULL;
    
    return ret;
#elif RECURSIVE
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *t = head->next;
    head->next = swapPairs(head->next->next);
    t->next = head;
    
    return t;
#endif
}
