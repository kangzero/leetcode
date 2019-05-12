/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define NATIVE_MERGE 0
#define BINARY_MERGE 1


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
#if NATIVE_MERGE 
        ListNode *ret = NULL;
        
        for (int i = 0; i < lists.size(); i++) {
            ret = mergeTwoList(ret, lists[i]);
        }
        
        return ret;
#elif BINARY_MERGE
        if (lists.empty()) return NULL;
        
        int r = lists.size() - 1;
        while (r > 0) {
            int l = 0;
            while (l < r) {
                lists[l] = mergeTwoList(lists[l], lists[r]);
                l++;
                r--;              
            }
        }
        
        return  lists[0];
#endif
    }
    
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        while ((l1 != NULL) && (l2 != NULL)) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
            
        cur->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
};
