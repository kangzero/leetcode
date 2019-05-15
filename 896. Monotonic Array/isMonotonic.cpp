class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true;
        bool dec = true;
        
        for (int i = 0; i < (A.size() - 1); i++) {
            if (A[i] > A[i+1]) {
                inc = false;
            }
            if (A[i] < A[i+1]) {
                dec = false;
            }
        }
        
        return (inc || dec);
    }
};
