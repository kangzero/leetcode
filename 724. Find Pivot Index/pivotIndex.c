

int pivotIndex(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    
    int left = 0, l = 0;

    while (l < numsSize) {
        if (left == (sum - left - nums[l])) return l;
        left += nums[l++];
    }
    
    return -1;
}

