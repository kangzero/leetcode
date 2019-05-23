#define BRUTE_FORCE 0
#define ONE_PASS    1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if BRUTE_FORCE
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                int tmp = prices[j] - prices[i];
                profit = (tmp > profit) ? tmp : profit;
            }
        }
        
        return profit;
#elif ONE_PASS
        int profit = 0;
        int minprice = INT_MAX;
        int maxprofit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice) {
                minprice = prices[i];
            } else {
                profit = (prices[i] - minprice);
                maxprofit = max(profit, maxprofit);
            }
        }
        
        return maxprofit;
#endif
    }
};
