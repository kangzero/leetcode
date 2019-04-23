class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret;
        vector<int> odd;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                ret.push_back(A[i]);
            } else {
                odd.push_back(A[i]);
            }
        }
        
        ret.insert(ret.end(), odd.begin(), odd.end());
        return ret;
    }
};
