//#define BRUTE_FORCE
#define HASH_MAP

#ifdef BRUTE_FORCE

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j = 0;
        vector<int> a(2, 0);
        
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[j] == (target - nums[i]) ) {
                    a[0] = i;
                    a[1] = j;
                    return a;
                }
            }
        }
        
        return {-1, -1};
    }
};

#elif defined HASH_MAP

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++) {
            auto p = map.find(target - nums[i]);
            if (p != map.end()) {
                return {p->second, i};
            }
            map[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};

#endif
