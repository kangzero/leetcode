class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp++;
            } else {
                tmp = 0;
            }
            ret = (ret > tmp) ? ret : tmp;
        }
        
        return ret;
    }
};
