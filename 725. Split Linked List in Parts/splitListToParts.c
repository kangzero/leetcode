/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
    if (k < 1) {
        *returnSize = 0;
        return NULL;
    }
    
    struct ListNode **ret = calloc(k, sizeof(struct ListNode));
    *returnSize = k;
    int n = getLength(root);
    int avg = n / k;
    int ext = n % k;
    
    for (int i = 0; (i < k) && (root != NULL); i++) {
        if (i < ext) {
            ret[i] = calloc((avg+1), sizeof(struct ListNode));
        } else {
            ret[i] = calloc(avg, sizeof(struct ListNode));
        }
        ret[i] = root;
        int t = 0;
        if (i < ext) {
            t = 1;
        }
        for (int j = 1; j < (avg + t); j++) {
            root = root->next;
        }
        struct ListNode *tmp = root->next;
        root->next = NULL;
        root = tmp;
    }
    
    return ret;
}

int getLength(struct ListNode* root) {
    int len = 0;
    struct ListNode *cur = root;
    
    while (cur != NULL) {
        len++;
        cur = cur->next;
    }
    
    return len;
}
