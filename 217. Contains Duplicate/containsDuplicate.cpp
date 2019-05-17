#define MAP     0
#define SET     1

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
#if MAP
        map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) != numsMap.end()) {
                return true;
            } else {
                numsMap[nums[i]] = 1;
            }
            
        }
        return false;
#elif SET
        set<int> numsSet;
        for (auto num : nums) {
            if (numsSet.find(num) != numsSet.end()) {
                return true;
            } else {
                numsSet.insert(num);
            }
        }
        return false;
#endif
    }
};
