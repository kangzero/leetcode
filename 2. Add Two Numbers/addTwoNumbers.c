/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0;
    int c = 0;
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    
    struct ListNode* head = calloc(1, sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    
    struct ListNode *cur = head;
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
        cur->next = calloc(1, sizeof(struct ListNode));
        cur->next->val = sum;
        cur = cur->next;
        if (p != NULL) {
            p = p->next;
        }
        if (q != NULL) {
            q = q->next;
        }
    }

    return head->next;
}

