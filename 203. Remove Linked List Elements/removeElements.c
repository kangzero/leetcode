/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{   
    if (head == NULL) return head;
    
    struct ListNode *tmp;
    while ((head != NULL) && (head->val == val))
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    if (head == NULL) return NULL;
    
    struct ListNode *prev, *next;
    next = head->next;
    prev = head;
    while (next != NULL)
    {
        if (next->val == val)
        {
            tmp = next;
            next = next->next;
            prev->next = next;
            free(tmp);
        } else {
            prev = next;
            next = next->next;
        }
    }
    
    tmp = NULL;
    return head;
}
