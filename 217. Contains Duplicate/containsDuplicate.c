
#define BRUTE_FORCE 0 // O(N^2) - TLE
#define SORTING 1 // O(NlgN)
#define HASH_TABLE 0

#if SORTING
bool containsDuplicate(int* nums, int numsSize);
int cmpInt(const void* a, const void* b);
#endif

#if BRUTE_FORCE
bool containsDuplicate(int* nums, int numsSize){
    for (int i = 0; i < (numsSize - 1); i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

#elif SORTING
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &cmpInt);
    for (int i = 0; i < (numsSize - 1); i++) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

#elif HASH_TABLE
//implemented by c++

#endif

