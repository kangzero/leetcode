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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret(k);
        
        int len = getLength(root);
        int avg = len / k;
        int ext = len % k;
        
        for (int i = 0; (i < k) && (root != NULL); i++) {
            ret[i] = root;
            int t = 0;
            if (i < ext) {
                t = 1;
            } else {
                t = 0;
            }
            for (int j = 1; j < (avg + t); j++) {
                root = root->next;
            }
            ListNode *tmp = root->next;
            root->next = NULL;
            root = tmp;
        }
        
        return ret;
    }
    
    int getLength(ListNode* head) {
        int len = 0;
        ListNode *cur = head;
        
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        
        return len;
    }
};
