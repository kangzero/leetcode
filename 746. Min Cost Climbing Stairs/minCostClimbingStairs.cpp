class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n, 0);
        
        if(n < 2) return 0;
        
        ans[0] = cost[0];
        ans[1] = cost[1];
        
        for (int i = 2; i < n; i++) {
            ans[i] = cost[i] + min(ans[i-2], ans[i-1]);
        }
        
        return min(ans[n-1], ans[n-2]);
    }
};
