/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define REVERSE_LIST 0
#define PADDING_ZERO 1

//#define _DEBUG

#if REVERSE_LIST
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    int carry = 0;
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    while ((p != NULL) || (q != NULL) || (carry == 1)) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
        int sum = x + y + carry;
        carry = sum / 10;
        cur->next = calloc(1, sizeof(struct ListNode));
        cur->next->val = sum % 10;
        cur = cur->next;
    }
    struct ListNode *head = dummy->next;
    free(dummy);
    dummy = NULL;
    return reverseList(head);
}

struct ListNode* reverseList(struct ListNode* head) {
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
}

#elif PADDING_ZERO
int getLength(struct ListNode* list);
struct ListNode* paddingZero(struct ListNode *list, int n);
struct ListNode* helper(struct ListNode* l1, struct ListNode* l2, int* c);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
              
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int n1 = getLength(l1);
    int n2 = getLength(l2);
    if (n1 > n2) l2 = paddingZero(l2, n1-n2);
    if (n1 < n2) l1 = paddingZero(l1, n2-n1);
#ifdef _DEBUG
    struct ListNode *tmp = l1;
    printf("l1: \n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    printf("l2: \n");
    tmp = l2;
    for (int i = 0; i < n1; i++) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");    
#endif    
    
    int carry = 0;
    struct ListNode *ret = helper(l1, l2, &carry);
    
    if (carry == 1) {
        struct ListNode *tmp = calloc(1, sizeof(struct ListNode));
        tmp->val  = 1;
        tmp->next = ret;
        ret = tmp;
    }
    
    return ret;
}

//DFS
struct ListNode* helper(struct ListNode* l1, struct ListNode* l2, int* carry) {
    if ((l1 == NULL) && (l2 == NULL)) return NULL;
    
    struct ListNode *node = helper(l1->next, l2->next, carry);
    int sum = l1->val + l2->val + *carry;
    *carry = sum / 10;
    struct ListNode *ret = calloc(1, sizeof(struct ListNode));
    ret->val = sum % 10;
    ret->next = node;
    return ret;
}

//padding n (n > 0) zeros at the head of list 
struct ListNode* paddingZero(struct ListNode *list, int n) {
    struct ListNode *head = calloc(1, sizeof(struct ListNode));
    struct ListNode *cur = head;
    cur->val = 0;
    for (int i = 0; i < n-1; i++) {
        cur->next = calloc(1, sizeof(struct ListNode));
        cur->val = 0;
        cur = cur->next;;
    }
    cur->next = list;
    return head;
}

//get the length of linkedlist
int getLength(struct ListNode* list) {
    struct ListNode *cur = list;
    int len = 0;
    
    while (cur != NULL) {
        len++;
        cur = cur->next;
    }
    
    return len;
}

#endif
