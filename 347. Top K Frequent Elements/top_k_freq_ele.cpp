//#define HEAP_SORT
#define BUCKET_SORT
//#define _DEBUG

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
#ifdef HEAP_SORT
        unordered_map<int, int> v;
        priority_queue<pair<int, int> > q;
        vector<int> res;
        
        for (auto n: nums) v[n]++;
        
        for (auto it: v) q.push({it.second, it.first});
        
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
#elif defined BUCKET_SORT
        unordered_map<int, int> v;
        vector<vector<int> > bucket(nums.size() + 1);
        vector<int> res;
        
        for (auto n: nums) v[n]++;

#ifdef _DEBUG
        for (auto it: v) {
            cout << it.first << " " << it.second << endl;
        }
#endif
        
        for (auto it: v) {
            bucket[it.second].push_back(it.first);
        }
        
        for (int i = nums.size(); i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
#endif
    }
};
