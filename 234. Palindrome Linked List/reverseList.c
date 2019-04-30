/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#define DEBUG
//#define REVERSE
//#define HALF_REVERSE
#define CONCISE_LIST_CHANGED

#ifdef CONCISE_LIST_CHANGED
struct ListNode* reverseList(struct ListNode* head);
    
bool isPalindrome(struct ListNode* head){
    if((head == NULL) || (head->next == NULL)){
        return true;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while((fast->next != NULL) && (fast->next->next != NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;
    slow = reverseList(slow);

    while((head != NULL) && (slow != NULL)){
        if(head->val != slow->val){
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

struct ListNode* reverseList(struct ListNode* head){
    if((head == NULL) || (head->next == NULL)){
        return head;
    } 
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur){
        struct ListNode* next = cur->next;
        cur->next = prev; //reverse happens here
        prev = cur;
        cur = next;
    }
    return prev;
}

#elif defined HALF_REVERSE
struct ListNode* reverseList(struct ListNode* head);
    
bool isPalindrome(struct ListNode* head){
    if((head == NULL) || (head->next == NULL)){
        return true;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* left = head;
    struct ListNode* right = NULL;
    
#ifdef DEBUG
    printf("Print List before Half reverse:\n");
    printList(head);
#endif
    
    while((fast->next != NULL) && (fast->next->next != NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow = slow->next;
    slow = reverseList(slow);
    right = slow;
#ifdef DEBUG
    printf("Print HALF List after reverse: \n");
    printList(right);
#endif
    while((left != NULL) && (right != NULL)){
        if(left->val != right->val){
            return false;
        }
        left = left->next;
        right = right->next;
    }
    
    right = reverseList(slow);
#ifdef DEBUG
    printf("Print HALF List after restore: \n");
    printList(right);
    printf("Print List After Reverse: \n");
    printList(head);
#endif
    return true;
}

struct ListNode* reverseList(struct ListNode* head){
    if((head == NULL) || (head->next == NULL)){
        return head;
    } 
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur){
        struct ListNode* next = cur->next;
        cur->next = prev; //reverse happens here
        prev = cur;
        cur = next;
    }
    return prev;
}

#ifdef DEBUG
void printList(struct ListNode* head){
    struct ListNode* cur = head;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
#endif

#elif defined REVERSE
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* copyList(struct ListNode* head);
void printList(struct ListNode* head);
int lengthList(struct ListNode* head);

bool isPalindrome(struct ListNode* head) {
    int len = lengthList(head);
    if(len < 2) return true;
    
    struct ListNode* cur = head;
    struct ListNode* rvs = copyList(cur);
    rvs = reverseList(rvs);
    
#ifdef DEBUG
    printList(rvs);
#endif
    
    while((cur != NULL) && (rvs != NULL)){
        //printf("rvs->val = %d, cur->val = %d \n", rvs->val, cur->val);
        if((rvs->val) != (cur->val)){
            freeList(rvs);
            return false;
        }
        rvs = rvs->next;
        cur = cur->next;
    }
    free(rvs);
    return true;
}

struct ListNode* copyList(struct ListNode* head){
    if(head == NULL) return NULL;
    
    struct ListNode* new = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;

    while(cur != NULL){
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = cur->val;
        temp->next = NULL;
        
        if(new == NULL){
            new = temp;
            prev = temp;
        }else{
            prev->next = temp;
            prev = temp;
        }
        cur = cur->next;
    }
    
    return new;
}

struct ListNode* reverseList(struct ListNode* head){
    if((head == NULL) || (head->next == NULL)){
        return head;
    } 
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur){
        struct ListNode* next = cur->next;
        cur->next = prev; //reverse happens here
        prev = cur;
        cur = next;
    }
    return prev;
}

int lengthList(struct ListNode* head){
    struct ListNode* cur = head;
    int len = 0;
    while(cur != NULL){
        len++;
        cur = cur->next;
    }
    return len;
}

void freeList(struct ListNode* head){
    struct ListNode* cur = head;
    while(cur != NULL){
        struct ListNode* prev = cur;
        cur = cur->next;
        free(prev);
    }
}

#ifdef DEBUG
void printList(struct ListNode* head){
    struct ListNode* cur = head;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
#endif
#endif
