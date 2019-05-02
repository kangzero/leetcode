/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define _CALLOC 1
#define _MALLOC 0

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0;
    int c = 0;
    struct ListNode *p = l1;
    struct ListNode *q = l2;

#if _CALLOC
    struct ListNode* dummy = calloc(1, sizeof(struct ListNode));
#elif _MALLOC
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
#endif
    
    struct ListNode *cur = dummy;
    while ((p != NULL) || (q != NULL) || (c == 1)) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        sum = x + y + c;
        if (sum >= 10) {
            sum -= 10;
            c = 1;
        } else {
            c = 0;
        }
#if _CALLOC
        cur->next = calloc(1, sizeof(struct ListNode));
#elif _MALLOC
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->next = NULL;
#endif        
        cur->next->val = sum;
        cur = cur->next;
        
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }

    return dummy->next;
}

