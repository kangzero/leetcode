#define BRUTE_FORCE 0
#define HASH_MAP 1

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
#if BRUTE_FORCE
        if (k == 0) return false;
        
        int i = 0;
        for (i = 0; i < (int)nums.size()-k; i++) {
            int j = i + 1;
            while ((j - i) <= k) {
                if (nums[i] == nums[j]) return true;
                j++;
            }
        }
        
        while (i < (nums.size()-1)) {
            if (nums[i] == nums[nums.size()-1]) return true;
            i++;
        }
        
        return false;
#elif HASH_MAP
        map<int, int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            if ((v.find(nums[i]) != v.end()) && (k >= (i - v[nums[i]]))) {
                return true;
            } else {
                v[nums[i]] = i;
            }
        }
        
        return false;
        
#endif
    }
};
