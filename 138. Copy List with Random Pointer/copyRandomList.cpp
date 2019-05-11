/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/


#define INTERLEAVE_COPY 0
#define HASH_MAP 1


class Solution {
public:
    Node* copyRandomList(Node* head) {
#if INTERLEAVE_COPY
        if (head == NULL) return NULL;
        
        //copy node->val & node->next and insert into the origin list
        Node *cur = head;
        while (cur != NULL) {
            Node *cpy = new Node(cur->val, NULL, NULL);
            cpy->next = cur->next;
            cur->next = cpy;
            cur = cur->next->next;
        }
        
        //copy node random pointer
        cur = head;
        while (cur != NULL) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        //extract copied list
        cur = head;
        Node *dummy = new Node(-1);
        Node *cp = dummy;
        while (cur != NULL) {
            cp->next = cur->next;
            cur->next = cur->next->next;
            cp = cp->next;
            cur = cur->next;
        }
        
        cp = dummy->next;
        delete dummy;
        dummy = NULL;
        
        return cp;
#elif HASH_MAP
        if (head == NULL) return NULL;
        
        Node *ret = new Node(head->val, NULL, NULL);
        Node *node = ret;
        Node *cur = head->next;
        
        map<Node*, Node*> m;
        m[head] = ret;
        
        while (cur != NULL) {
            Node *tmp = new Node(cur->val, NULL, NULL);
            node->next = tmp;
            m[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        
        node = ret;
        cur = head;
        while (node != NULL) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        
        return ret;
#endif
    }
};
