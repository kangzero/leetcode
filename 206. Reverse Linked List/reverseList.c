/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define RECURSIVE 0
#define ITERATIVE 1
struct ListNode* reverseList(struct ListNode* head) {
#if RECURSIVE
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return p;
#elif ITERATIVE
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    
    while (cur != NULL) {
        struct ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    
    return pre;
#endif
}
