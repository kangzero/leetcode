/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp;
        while ((head != nullptr) && (head->val == val)){
            tmp = head;
            head = head->next;
            delete tmp;
        }

        if (head == nullptr) return NULL;

        struct ListNode* prev = head;
        struct ListNode* next = head->next;
        while (next != NULL) {
            if (next->val == val) {
                tmp = next;
                next = next->next;
                prev->next = next;
                delete tmp;
            } else {
                next = next->next;
                prev = prev->next;
            }
        }

        tmp = nullptr;
        return head;  
    }
};
