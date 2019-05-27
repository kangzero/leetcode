class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int cnt = INT_MIN;
        int tmp = 1;

        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i+1] <= nums[i]) {
                tmp = 1;
            } else {
                tmp++;
            }
            cnt = (cnt > tmp) ? cnt : tmp;
        }
        
        return cnt;
    }
};
