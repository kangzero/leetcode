class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numsSet;
        
        for (auto num : nums) numsSet.insert(num);
        
        for (int i = 0; i <= nums.size(); i++) {
            if (numsSet.find(i) == numsSet.end()) return i;
        }
        
        return -1;
    }
};
