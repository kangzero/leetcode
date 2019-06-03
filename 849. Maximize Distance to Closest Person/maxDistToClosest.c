

int maxDistToClosest(int* seats, int seatsSize){
    int ret = 0;
    
    int k = 0;
    int* nums = malloc(seatsSize * sizeof(int));
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 1) nums[k++] = i;
    }
    
    ret = (ret > nums[0]) ? ret : nums[0];
    for (int i = 1; i < k; i++) {
        int tmp = (nums[i] - nums[i-1]) / 2;
        ret = (ret > tmp) ? ret : tmp;
    }
    
    int t = seatsSize - 1 - nums[k-1];
    if (k != 0) ret = (ret > t) ? ret : t;
    
    free(nums);
    nums = NULL;
    
    return ret;
}

