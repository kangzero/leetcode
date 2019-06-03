class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ret = 0;
        
        int n = seats.size();
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) nums.push_back(i);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ret = max(ret, nums[0]); 
            } else {
                ret = max(ret, (nums[i] - nums[i-1]) / 2); 
            }
        }
        
        if (nums.empty() == 0) ret = max(ret, (n - 1 - nums.back()));
        
        return ret;
    }
};
