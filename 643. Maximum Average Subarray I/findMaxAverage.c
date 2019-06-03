

double findMaxAverage(int* nums, int numsSize, int k){
    double sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];

    double tmp = sum;
    for (int i = k; i < numsSize; i++) {
        tmp += nums[i] - nums[i-k];
        sum = (sum > tmp) ? sum : tmp;
    }
    
    return sum/k;
}

