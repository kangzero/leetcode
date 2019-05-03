/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define REVERSE 0
#define NON_REVERSE 1

#define REVERSE_RECURSIVE 0
#define REVERSE_ITERATIVE 1
//#define _DEBUG

#if REVERSE
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
#ifdef _DEBUG
        print_list(l1);
        print_list(l2);
#endif
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode* head = new ListNode(0);
        int carry = 0;
        if ((cur1->val + cur2->val) > 9) {
            head->val = (cur1->val + cur2->val) - 10;
            carry = 1;
        } else {
            head->val = cur1->val + cur2->val;
        }
        
        cur1 = cur1->next;
        cur2 = cur2->next;
        ListNode* cur = head;
        while ((cur1 != nullptr) || (cur2 != nullptr) || (carry == 1)) {
            int x = (cur1 == nullptr) ? 0 : cur1->val;
            int y = (cur2 == nullptr) ? 0 : cur2->val;
            int sum = x + y + carry;
#ifdef _DEBUG
            cout << sum << endl;
#endif
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);    
            cur = cur->next;
            if (cur1 != nullptr) cur1 = cur1->next;
            if (cur2 != nullptr) cur2 = cur2->next;
        }
                
        return reverseList(head);
    }
    
    ListNode* reverseList(ListNode* head) {
#if REVERSE_RECURSIVE
        if ((head == nullptr) || (head->next == nullptr)) return head;
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
#elif REVERSE_ITERATIVE
        if ((head == nullptr) || (head->next == nullptr)) return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev; //reverse happens here
            prev = cur;
            cur = next;
        }
        return prev;
#endif
    }

#ifdef _DEBUG
    void print_list (ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << "NULL" << endl;
        return;
    }
#endif
};

#elif defined NON_REVERSE
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = sizeList(l1);
        int n2 = sizeList(l2);
        
        if (n1 > n2) l2 = padList(l2, n1-n2);
        if (n1 < n2) l1 = padList(l1, n2-n1);
        int carry = 0;
        
        ListNode *ret = helper(l1, l2, carry);
        
        if (carry == 1) {
            ListNode *t = new ListNode(1);
            t->next = ret;
            ret = t;
        }
        
        return ret;
    }
    
    ListNode *helper(ListNode* l1, ListNode* l2, int &c) {
        if ((l1 == nullptr) && (l2 == nullptr)) return nullptr;
        
        ListNode *node = helper(l1->next, l2->next, c);
        int sum = l1->val + l2->val + c;
        ListNode *ret = new ListNode(sum % 10);
        c = sum / 10;
        ret->next = node;
        return ret;
    }
    
    //padding 0 before the shorter list (n > 0)
    ListNode* padList(ListNode* list, int n) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        
        for (int i = 0; i < n-1; i++) {
            cur->next = new ListNode(0);
            cur = cur->next;
        }  
        cur->next = list;
        
        return head;
    }
    
    //get the list length
    int sizeList(ListNode* head) {
        int cnt = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }
};
#endif
