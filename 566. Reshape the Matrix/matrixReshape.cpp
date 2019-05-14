#define ONE_LOOP 1
#define TWO_LOOP 0

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if ((m * n) != (r * c)) return nums;
        
        vector<vector<int>> ret(r, vector<int>(c));
#if ONE_LOOP
        for (int i = 0; i < r*c ; i++) {
            ret[i/c][i%c] = nums[i/n][i%n];
        }
#elif TWO_LOOP
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int k = i * c + j;
                ret[i][j] = nums[k/n][k%n];
            }
        }
#endif

        return ret;
    }
};
