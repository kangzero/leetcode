#define SORT 0
#define BUCKET 1

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
#if SORT
        int ret = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            ret += nums[i];
        }
        
        return ret;
#elif BUCKET
        int ret = 0;
        
        vector<int> array(20001, 0);
        for (int i = 0; i < nums.size(); i++) {
            array[nums[i]+10000]++;
        }
        
        int index = 0;
        int count = 0;
        bool flag = true;
        while ((index < 20001) && (count < (nums.size() / 2))) {
            if (array[index] > 0) {
                if (flag) {
                    flag = false;
                    ret += (index - 10000);
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
        
#endif
    }
};
