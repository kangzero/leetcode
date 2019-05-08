/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head);

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if ((head == NULL) || (head->next == NULL)) return head;
    
    struct ListNode *m_node = NULL;
    struct ListNode *n_node = NULL;
    struct ListNode *m_prev = NULL;
    struct ListNode *n_next = NULL;
    struct ListNode *cur = head;
    int cnt = 1;
    while ((cur != NULL) && (cnt <= n)) {
        if (cnt < m) {
            m_prev = cur;
        }
        if (m == cnt) {
            m_node = cur;
        }
        if (n == cnt) {
            n_node = cur;
            n_next = cur->next;
        }
        cur = cur->next;
        cnt++;
    }
    
    n_node->next = NULL;
    n_node = reverseList(m_node);
    if (m_prev != NULL) {
        m_prev->next = n_node;
    } else {
        head = n_node;
    }
    m_node->next = n_next;

    return head;
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
