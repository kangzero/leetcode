class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret;
        ret.reserve(A.size()+1);
        for (int i = A.size()-1; (i >= 0) || (K > 0); i--) {
            K += (i >= 0) ? A[i] : 0;
            ret.push_back(K % 10);
            K /= 10;
        }
        reverse(begin(ret), end(ret));
        return ret;
    }
};
