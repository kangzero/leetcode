/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if ((l1 == NULL) || (l2 == NULL)) return (l1 != NULL) ? l1 : l2;

    struct ListNode *head = NULL;
    if (l1->val < l2->val) 
    {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    
    struct ListNode *cur = head;
    while ((l1 != NULL) && (l2 != NULL))
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    
    cur->next = (l1 != NULL) ? l1 : l2;
    
    return head;
}

