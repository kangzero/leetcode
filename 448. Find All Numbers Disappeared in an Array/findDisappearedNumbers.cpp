class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int pos = ~(1u << 31);
        const int neg = (1u << 31);
        
        for (int i = 0; i < nums.size(); i++) {
            nums[(nums[i] & pos) - 1] = nums[(nums[i] & pos) - 1] | neg;
        }
        
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ret.push_back(i+1);
            }
        }
        
        return ret;
    }
};
