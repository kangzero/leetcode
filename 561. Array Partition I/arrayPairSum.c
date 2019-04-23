int arrayPairSum(int* nums, int numsSize) {
    int ret = 0;
    
    int array[20001] = {0};
    for (int i = 0; i < numsSize; i++) {
        array[nums[i] + 10000]++;
    }
    
    int index = 0;
    int count = 0;
    bool flag = true;
    
    while ((index < 20001) && (count < (numsSize/2))) {
        if (array[index] > 0) {
            if (flag) {
                ret += (index - 10000);
                flag = false;
                array[index]--;
                count++;
            } else {
                flag = true;
                array[index]--;
            }
        } else {
            index++;
        }
    }
    
    return ret;
}
