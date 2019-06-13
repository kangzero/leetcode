class Solution {
public:
    int thirdMax(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int cnt = 1;
        
        if (len >= 3) {
            for (int i = (len-2); i >= 0; i--) {
                if (nums[i] != nums[i+1]) {
                    cnt += 1;
                }
                if (cnt == 3) {
                    return nums[i];
                }
            }
        }
        
        return nums[len-1];
    }
};
