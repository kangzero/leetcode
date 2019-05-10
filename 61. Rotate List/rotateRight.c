/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *cur = head;
    int len = 1;
    while (cur->next != NULL) {
        len++;
        cur = cur->next;
    }
    
    k %= len; //in case of (k > len)
    if (k == 0) return head;
    
    struct ListNode *tail = head;
    for (int i = 1; i < (len-k); i++) {
        tail = tail->next;
    }
    
    struct ListNode *ret = tail->next;
    tail->next = NULL;
    cur->next = head;
        
    return ret;
}
