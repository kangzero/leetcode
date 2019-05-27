#define SOL1 1
#define SOL2 0

int removeElement(int* nums, int numsSize, int val) {
#if SOL1
    if (numsSize == 0) return 0;
    
    int len = numsSize;
    int i = 0;
    
    while(i < len) {
        if (nums[i] == val) {
            nums[i] = nums[len-1];
            len--;
        } else {
            i++;
        }
    }
    
    return len;
#elif SOL2
    int idx = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;
#endif
}

