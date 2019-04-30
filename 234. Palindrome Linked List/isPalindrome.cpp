/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define STACK_CMP 0
#define HALF_REVERSE 1

class Solution {
public:
    bool isPalindrome(ListNode* head) {
#if STACK_CMP
        if ((nullptr == head) || (nullptr == head->next)) return true;
        
        stack<int> s;
        ListNode *slow = head;
        ListNode *fast = head;
        s.push(slow->val);
        while ((nullptr != fast->next) && (nullptr != fast->next->next)) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        
        if (nullptr == fast->next) s.pop();
        while (nullptr != slow->next) {
            int v = s.top();
            s.pop();
            slow = slow->next;
            if (v != slow->val) return false;
        }
        
        return true;
#elif HALF_REVERSE
        if ((nullptr == head) || (nullptr == head->next)) return true;
        
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        
        while ((nullptr != fast->next) && (nullptr != fast->next->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        struct ListNode *hal = slow->next;
        struct ListNode *pre = nullptr;
        while (nullptr != hal) {
            struct ListNode *next = hal->next;
            hal->next = pre;
            pre = hal;
            hal = next;
        }
        
        struct ListNode *p1 = head;
        struct ListNode *p2 = pre;
        while (nullptr != p2) {
            if (p2->val != p1->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
#endif  
    }
};
