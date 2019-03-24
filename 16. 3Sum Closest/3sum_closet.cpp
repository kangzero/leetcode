class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        
        int res = 0;
        for (int i = 0; i < 3; i++) {
            res += v[i];
        }
        
        for(int i = 0; i < (int)(v.size() - 2); i++) {
            if ((i > 0) && (v[i] == v[i-1])) continue; //skip duplicated element at i
            
            int l = i + 1;
            int r = v.size() - 1;
            
            while(l < r) {
                int tmp = v[i] + v[l] + v[r];
                
                if (tmp == target) return tmp;
                
                if ((tmp - target) > 0) {
                    res = (abs(tmp - target) < abs(res -target)) ? tmp : res;
                    r--;
                } else {
                    res = (abs(tmp - target) < abs(res -target)) ? tmp : res;
                    l++;
                }
            }
        }

        return res;
    }
};
