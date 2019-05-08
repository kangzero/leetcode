/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head;
    
    while (ptr1 != NULL) {
        ptr1 = ptr1->next;
        if (n-- < 0) {
            ptr2 = ptr2->next;
        }
    }
    
    struct ListNode *tmp = ptr2->next;
    if (n == 0) {
        tmp = head;
        head = head->next;
    } else {
        ptr2->next = ptr2->next->next;
    }

    free(tmp);
    tmp = NULL;
    
    return head;
}

