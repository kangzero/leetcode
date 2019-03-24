//#define BRUTE_FORCE
//#define HASH_MAP
#define SORT_GREEDY

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    
#ifdef BRUTE_FORCE
        int i, j = 0;
        vector<int> ret(2, -1);
        
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[j] == (target - nums[i]) ) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;
#elif defined HASH_MAP
        unordered_map<int, int> map;
        vector<int> res(2, -1);
        
        for(int i=0; i<nums.size(); i++) {
            auto p = map.find(target - nums[i]);
            if (p != map.end()) {
                res[0] = p->second;
                res[1] = i;
                return res;
            }
            map[nums[i]] = i;
        }
        return res;     
#elif defined SORT_GREEDY
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
            cout << v[i] << " ";
        }
        cout << endl;
        
        sort(v.begin(), v.end());
        int l = 0;
        int r = v.size() - 1;
        int p = 0, q = 0;
        while (l < r) {
            if ((v[l] + v[r]) > target) {
                r--;
            } else if ((v[l] + v[r]) < target) {
                l++;
            } else {
                cout << l << " " << r << endl;
                p = v[l];
                q = v[r];
                break;
            }
        }
        
        vector<int> res;
        for (int i = 0; (i < nums.size()) & (res.size() < 2); i++) {
            if ((nums[i] == p) || (nums[i] == q)) {
                res.push_back(i);
            }
        }
        return res;
#endif    
    }
};
