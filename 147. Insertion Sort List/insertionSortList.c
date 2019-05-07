/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    struct ListNode *pivot = head;
    
    while (pivot != NULL) {
        struct ListNode *tmp = pivot->next;
        struct ListNode *cur = dummy;
        while ((cur->next != NULL) && (cur->next->val <= pivot->val)) {
            cur = cur->next;
        }
        pivot->next = cur->next;
        cur->next = pivot;
        pivot = tmp;
    }
    
    struct ListNode *p = dummy->next;
    free(dummy);
    dummy = NULL;
    
    return p;
}
