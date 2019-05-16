
#define BRUTE_FORCE     0 // O(N^2), TLE
#define SORT_SEARCH     0 // O(NlgN)
#define HASH_MAP        0 
//#define DIVIDE_CONQUER  1 // O(NlgN)
#define BOYER_MOORE_VOTING  1 // O(N)


#if SORT_SEARCH
int majorityElement(int* nums, int numsSize);
int cmpInt(const void *a, const void *b);
/*
#elif DIVIDE_CONQUER
int majorityElement(int* nums, int numsSize);
int majorityHelper(int* nums, int l, int r);
int count(int *nums, int n, int left, int right); */
#endif


#if BRUTE_FORCE
int majorityElement(int* nums, int numsSize) {
    int majority = numsSize / 2;
    
    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == nums[i]) cnt++;
            if (cnt > majority) return nums[j];
        }
    }
    
    return 0;
}
#elif SORT_SEARCH
int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &cmpInt);
    return nums[numsSize/2];
}

int cmpInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
/*
#elif HASH_MAP
// implemented by c++
#elif DIVIDE_CONQUER
int majorityElement(int* nums, int numsSize) {
    return majorityHelper(nums, 0, numsSize-1);
}

int majorityHelper(int* nums, int l, int r) {
    if (l == r) return nums[l];
    
    int m = (r - l) / 2 + l;
    int left = majorityHelper(nums, l, m);
    int right = majorityHelper(nums, m+1, r);
    
    if (left == right) return left;
    
    int left_count = count(nums, left, l, r);
    int right_count = count(nums, right, l, r);
    
    return (left_count > right_count) ? left_count : right_count;
}

int count(int *nums, int n, int l, int r) {
    int count = 0;
    
    for (int i = l; i <= r; i++) {
        if (nums[i] == n) {
            count++;
        }
    }
    
    return count;
} */
#elif BOYER_MOORE_VOTING
int majorityElement(int* nums, int numsSize) {
    int candidate;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if ((count == 0) || candidate == nums[i]) {
            candidate = nums[i];
            count++;
        } else {
            count--;
        }
    }
    
    return candidate;
}
#endif

