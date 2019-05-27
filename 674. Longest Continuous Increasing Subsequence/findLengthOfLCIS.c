

int findLengthOfLCIS(int* nums, int numsSize){
    if (numsSize <= 1) return numsSize;
    
    int cnt = INT_MIN;
    int tmp = 1;
    for (int i = 0; i < (numsSize-1); i++) {
        if (nums[i+1] <= nums[i]) {
            tmp = 1;
        } else {
            tmp++;
        }
        cnt = (cnt > tmp) ? cnt : tmp;
    }
    
    return cnt;
}

