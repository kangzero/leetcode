/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define INSERT_LIST
//#define VECTOR_SORT

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
#ifdef INSERT_LIST
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* pivot = head;
        
        while (pivot != nullptr) {
            ListNode* tmp = pivot->next;
            ListNode* cur = dummy;
            while ((cur->next != nullptr) && (cur->next->val <= pivot->val)) {
                cur = cur->next;
            }
            pivot->next = cur->next;
            cur->next = pivot;
            pivot = tmp;
        }
        
        pivot = dummy->next;
        delete dummy;
        dummy = nullptr;
        
        return pivot;
#elif defined VECTOR_SORT
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        vector<int> nums;
        ListNode* cur = head;
        while (cur != nullptr) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        
        sort(nums.begin(), nums.end());
        cur = head;
        while (nums.empty() == 0) {
            cur->val = nums.front();
            nums.erase(nums.begin());
            cur = cur->next;
        }
        
        return head;
#endif
    }
};
