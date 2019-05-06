/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* dummy_l = calloc(1, sizeof(struct ListNode));
    struct ListNode* dummy_r = calloc(1, sizeof(struct ListNode));
    
    struct ListNode* l = dummy_l;
    struct ListNode* r = dummy_r;
    
    struct ListNode* cur = head;
    while (cur != NULL) {
        if (cur->val < x) {
            l->next = cur;
            l = l->next;
        } else {
            r->next = cur;
            r = r->next;
        }
        cur = cur->next;
    }
    l->next = dummy_r->next;
    r->next = NULL;
    
    struct ListNode* ret = dummy_l->next;
    free(dummy_l);
    dummy_l = NULL;
    free(dummy_r);
    dummy_r = NULL;
    
    return ret;
}
