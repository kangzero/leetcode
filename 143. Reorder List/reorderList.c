/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL)) return;
    
    //split the list into 2 partitions, find the mid postion
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while ((fast != NULL) && (fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* t = slow;
    slow = slow->next;
    t->next = NULL;
    
    //revser right partition
    struct ListNode *p1 = head;
    struct ListNode *p2 = NULL;
    if ((slow == NULL) || (slow->next == NULL)) p2 = slow;
    struct ListNode *cur = slow;
    struct ListNode *pre = NULL;
    while (cur != NULL) {
        struct ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    p2 = pre;
    
    //merge two partition
    while ((p1 != NULL) && (p2 != NULL)) {
        struct ListNode *tmp1 = p1->next;
        struct ListNode *tmp2 = p2->next;
        p1->next = p2;
        p2->next = tmp1;
        p1 = tmp1;
        p2 = tmp2;
    }
}

