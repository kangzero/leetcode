#define BRUTE_FORCE 0 //TLE
#define SORTING 0
#define ONA_PASS 1

#if BRUTE_FORCE
int maximumProduct(int* nums, int numsSize) {
    int ret = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            for (int k = j+1; k < numsSize; k++) {
                int tmp = nums[i] * nums[j] * nums[k];
                ret = (ret > tmp) ? ret : tmp;
            }
        }
    }
    
    return ret;
}

#elif SORTING 
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
//#define _DEBUG

int cmpInt(const void* a, const void* b);
int maximumProduct(int* nums, int numsSize);
    
int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &cmpInt);
    return MAX(nums[0]*nums[1]*nums[numsSize-1], nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3]);
}

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

#elif ONA_PASS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int maximumProduct(int* nums, int numsSize) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] <= min2) {
            min2 = nums[i];
        }
        if (nums[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] >= max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] >= max3) {
            max3 = nums[i];
        }
    }
#ifdef _DEBUG
    printf("min1 = %d, min2 = %d \n", min1, min2);
    printf("max1 = %d, max2 = %d, max3 = %d\n", max1, max2, max3);
#endif
    return MAX((min1*min2*max1), (max1*max2*max3));
}

#endif

