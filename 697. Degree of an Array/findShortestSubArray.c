
int findShortestSubArray(int* nums, int numsSize) {
    int count[50000] = {0};
    int first[50000] = {0};
    
    int degree = 0;
    int ret = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 0) {
            first[nums[i]] = i;
        }
        count[nums[i]]++;
        if (count[nums[i]] > degree) {
            degree++;
            ret = i - first[nums[i]] + 1;
        } else if (count[nums[i]] == degree) {
            ret = (ret < (i - first[nums[i]] + 1)) ? ret : (i - first[nums[i]] + 1);
        }
    }
    
    return ret;
}
