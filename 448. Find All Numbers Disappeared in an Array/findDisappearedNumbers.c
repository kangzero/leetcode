/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    const unsigned int pos = ~(1u << 31);
    const unsigned int neg = (1u << 31);
    
    for (int i = 0; i < numsSize; i++) {
        nums[(nums[i] & pos) - 1] = nums[(nums[i] & pos) - 1] | neg;
    }
    
    int *ret = calloc(numsSize, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            ret[(*returnSize)++] = i + 1;
        }
    }

    return ret;
}
