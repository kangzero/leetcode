/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode* odd_cur = head;
    struct ListNode* even_head = head->next;
    struct ListNode* even_cur = even_head;
    
    while((even_cur != NULL) && (even_cur->next != NULL) )
    {
        odd_cur->next = odd_cur->next->next;
        odd_cur = odd_cur->next;
        even_cur->next = even_cur->next->next;
        even_cur = even_cur->next;
    }
    
    odd_cur->next = even_head;
    
    return head;
}
