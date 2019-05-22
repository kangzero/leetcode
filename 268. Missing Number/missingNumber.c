
#define SORTING 0
#define BIT_MANIPULATION 0
#define MATH_GAUSS 1

#if SORTING
int missingNumber(int* nums, int numsSize);
int cmpInt(const void* a, const void* b);

int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &cmpInt);
    
    if (nums[0] != 0) return 0;
    if (nums[numsSize-1] != numsSize) return numsSize;
    
    for (int i = 1; i < numsSize; i++) {
        if ((nums[i] - nums[i-1]) != 1) return nums[i]-1;
    }
    
    return -1;
}

int cmpInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

#elif BIT_MANIPULATION
int missingNumber(int* nums, int numsSize) {
    int ret = numsSize;
    int idx = 0;
    while (idx < numsSize) {
        ret ^= (nums[idx] ^ idx);
        idx++;
    }
    return ret;
}

#elif MATH_GAUSS
int missingNumber(int* nums, int numsSize) {
    int sum = numsSize * (numsSize + 1) / 2;
    int realsum = 0;
    for (int i = 0; i < numsSize; i++) realsum += nums[i];
    return sum - realsum;
}
#endif

