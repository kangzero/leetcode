/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define BRUTE_FORCE 0
#define MONOTONIC_STACK 1

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
#if BRUTE_FORCE
        vector<int> ret;
        
        if (head == nullptr) return {};
        if ((head != nullptr) && (head->next == nullptr)) {
            ret.push_back(0);
            return ret;
        }
        
        ListNode *cur = head;
        while (cur->next != nullptr) {
            ListNode *tmp = cur->next;
            while ((tmp !=nullptr) && (tmp->val <= cur->val)) {
                tmp = tmp->next;
            }
            if (tmp != nullptr) {
                ret.push_back(tmp->val);
            } else {
                ret.push_back(0);
            }
            cur = cur->next;
        }
        ret.push_back(0);
        
        return ret;
#elif MONOTONIC_STACK
        vector<int> nums;
        
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        stack<int> s;
        vector<int> ret(nums.size());
        for (int i = nums.size()-1; i >= 0; i--) {
            while (!s.empty() && (s.top() <= nums[i]))  s.pop();
            ret[i] = s.empty() ? 0 : s.top();
            s.push(nums[i]);
        }
        
        return ret;    
#endif
    }
};
