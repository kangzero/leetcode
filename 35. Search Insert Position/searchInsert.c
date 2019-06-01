#define ONE_PASS 0
#define BINARY_SEARCH 1

int searchInsert(int* nums, int numsSize, int target) {
#if ONE_PASS
    int k = 0;
    
    for (k = 0; k < numsSize; k++) {
        if ((nums[k] == target) ||(nums[k] > target)) {
            return k;
        } 
    }
    
    return k;
#elif BINARY_SEARCH
    int l = 0;
    int r = numsSize - 1;
    int m = 0;
    
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] > target) {
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else if (nums[m] == target) {
            return m;
        }
    }

    return l;
#endif
}
