

int dominantIndex(int* nums, int numsSize) {
    int index = -1;
    
    int m = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (m < nums[i]) {
            m = nums[i];
            index = i;
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        if ((m != nums[i]) && (2*nums[i] > m)){
            return -1;
        }
    }
    
    return index;
}

