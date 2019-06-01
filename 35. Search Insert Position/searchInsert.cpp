#define ONE_PASS 1
#define BINARY_SEARCH 0

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
#if ONE_PASS
        int idx = 0;
        
        for (idx = 0; idx < nums.size(); idx++) {
            if ((nums[idx] == target) || (nums[idx] > target)) return idx;
        }
        
        return idx;
#elif BINARY_SEARCH
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r--;
            } else if (nums[m] < target) {
                l++;
            } else {
                return m;
            }
        }
        
        return l;
#endif
    }
};
