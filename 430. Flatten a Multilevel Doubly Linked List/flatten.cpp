/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if ((head == NULL) || ((head->next == NULL) && (head->child == NULL))) return head;
        
        Node* cur = head;
        while (cur != NULL) {
            if (cur->child == NULL) {
                cur = cur->next;
                continue;
            } 
            
            Node* chd = cur->child;
            Node* chd_tail = chd;
            while (chd_tail->next != NULL) {
                chd_tail = chd_tail->next;
            }
            
            cur->child = NULL;
            chd->prev = cur;
            chd_tail->next = cur->next;
            if (cur->next != NULL) cur->next->prev = chd_tail;
            cur->next = chd;
            cur = cur->next;
        }
        
        return head;
    }
};
