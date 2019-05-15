#define COUNT 1
#define SUM 0

int findMaxConsecutiveOnes(int* nums, int numsSize) 
{
#if COUNT
    int ret = 0;
    int cnt = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }

        ret = (ret > cnt) ? ret : cnt;
    }
    
    return ret;
#elif SUM
    int ret = 0;
    int sum = 0;
    
    for (int i = 0; i < numsSize; i++) 
    {
        sum = (sum + nums[i]) * nums[i];
        ret = (ret > sum) ? ret : sum;
    }
    
    return ret;
#endif
}
