class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> count;
        unordered_map<int, pair<int, int>> pos;
        
        int degree = 0;
        int ret = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
            if (count[nums[i]] == 1) {
                pos[nums[i]] = {i, i};
            } else {
                pos[nums[i]].second = i;
            }
            degree = max(degree, count[nums[i]]);
        }
        
        for (auto c: count) {
            if (degree == c.second) {
                ret = min(ret, (pos[c.first].second - pos[c.first].first + 1));
            }
        }
        
        return ret;
    }
};
