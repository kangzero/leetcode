class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        int k = A.size() - 1;
        int l = 0;
        int r = A.size() - 1;
        
        while ((l <= r) && (k >= 0)) {
            if (abs(A[l]) > abs(A[r])) {
                ret[k--] = pow(A[l++], 2);
            } else {
                ret[k--] = pow(A[r--], 2);
            }
        }
        
        return ret;
    }
};
