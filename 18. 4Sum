class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < (int)(v.size() - 3); i++) {
            //skip duplicated element at i
            if ((i > 0) && (v[i] == v[i-1])) continue; 
            //break if sum of most 4 elements is larger than target
            if((v[i] + v[i+1] + v[i+2] + v[i+3]) > target) break; 
            //skip if sum of least 4 elements plus v[i] is smaller than target
            if((v[i] + v[v.size()-3] + v[v.size()-2]+ v[v.size()-1]) < target) continue; 
            
            for (int j = (i + 1); j < (int)(v.size() - 2); j++) {
                if ((j > (i+1)) && (v[j] == v[j-1])) continue;
                if(v[i] + v[j] + v[j+1] + v[j+2] > target) break;
                if(v[i] + v[j] + v[v.size()-2]+ v[v.size()-1] < target) continue;
                
                int l = j + 1;
                int r = v.size() - 1;
                while(l < r) {
                    if ((v[i] + v[j] + v[l] + v[r]) < target) {
                        l++;
                    } else if ((v[i] + v[j] + v[l] + v[r] > target)) {
                        r--;
                    } else {
                        res.push_back(vector {v[i], v[j], v[l], v[r]});
                        while ((v[l] == v[l+1]) && ((l+1) < r)) l++; //skip duplicated element at l+1
                        while ((v[r] == v[r-1]) && (l < r)) r--; //skip duplicated element at r-1
                        l++;
                        r--;
                    }
                }
            }
        }
        
        return res;      
    }
};
