/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define GRAPH_TRAVERSE_DFS 0
#define HASH_SET_COUNT 1
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
#if GRAPH_TRAVERSE_DFS
    //will implemented later...
#elif HASH_SET_COUNT
        unordered_set<int> gset(G.begin(), G.end());
        int ret = 0;
        
        while (head != nullptr) {
            if ((gset.count(head->val) != 0) && ((head->next == nullptr) || (gset.count(head->next->val) == 0))) {
                ret++;
            }
            head = head->next;
        }
        
        return ret;
#endif
    }
};
