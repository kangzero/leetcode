//#define BRUTE_FORCE_TLE
#define SORT_GREEDY

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
#ifdef BRUTE_FORCE_TLE //not AC because of TLE
        unordered_map<int, int> map;
        vector<vector<int>> ret;
        vector<int> temp;
        bool flag = 0;
        
        int i = 0, j = 0, k = 0;
        for (i = 0; i < nums.size(); i++){
            map[nums[i]] = i; 
        }
        for(i = 0; i < nums.size(); i++){
            for(j = (i + 1); j < nums.size(); j++){
                flag = 0;
                auto p = map.find((nums[i] + nums[j])*(-1));
                if((p != map.end()) && (p->second > j) && (j > i)){
                    temp = {nums[i], nums[j], p->first};
                    sort(temp.begin(), temp.end());
                    for(int k = 0; k < ret.size(); k++){
                        if(ret[k] == temp){
                            flag = 1;
                            break;
                        }
                    } 
                    if(!flag)
                        ret.push_back(temp);
                }
            }
        }
        
        return ret;    
#elif defined SORT_GREEDY
        vector<int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        
        vector<vector<int>> res;
        //must cast to int as v.size return a t_size variable
        for(int i = 0; i < (int)(v.size() - 2); i++) {
            if ((i > 0) && (v[i] == v[i-1])) continue; //skip duplicated element at i
            if (v[i] > 0) break;
            int l = i + 1;
            int r = v.size() - 1;
            while(l < r) {
                if ((v[i] + v[l] + v[r]) < 0) {
                    l++;
                } else if ((v[i] + v[l] + v[r] > 0)) {
                    r--;
                } else {
                    res.push_back(vector {v[i], v[l], v[r]});
                    while ((v[l] == v[l+1]) && ((l+1) < r)) l++; //skip duplicated element at l+1
                    while ((v[r] == v[r-1]) && (l < r)) r--; //skip duplicated element at r-1
                    l++;
                    r--;
                }
            }
        }

        return res;
#endif
    }
};
