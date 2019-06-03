class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int cnt = 1;
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[k] != nums[i]) {
                cnt += 1;
                nums[k+1] = nums[i];
                k++;
            }
        }
        
        return cnt;
    }
};
