/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define BRUTE_FORCE 0
#define TWO_POINTER 0
#define TWO_CONCAT 1

#if TWO_CONCAT
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    if((headA == NULL) || (headB == NULL)) return NULL;
    
    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;
    
    while (p1->next != NULL) {
        p1 = p1->next;
    }
    struct ListNode *p1_tail = p1;
    p1->next = p2;
    
    p1 = headA;
    p2 = headA;
    while ((p2 != NULL) && (p2->next != NULL)) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            p1 = headA;
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1_tail->next = NULL;
            return p1;
        }
    }
    
    p1_tail->next = NULL;
    return NULL;
}
#elif TWO_POINTER
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;

    while(curA != curB){
        curA = (curA != NULL) ? curA->next : headB;
        curB = (curB != NULL) ? curB->next : headA;
    }
    
    return curA;
}
#elif BRUTE_FORCE
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    
    while(curA != NULL){
        while(curB != NULL){
            if(curB == curA){
                return curA;
            }
            curB = curB->next;
        }
        curB = headB;
        curA = curA->next;
    } 
    
    return NULL;
}
#endif
