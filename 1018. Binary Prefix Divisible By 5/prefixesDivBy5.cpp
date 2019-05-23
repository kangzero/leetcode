class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        if (A.size() == 0) return ret;
        
        int tmp = 0;
        for (int i = 0; i < A.size(); i++) {
            tmp = (2 * tmp + A[i]) % 5;
            ret.push_back((tmp == 0) ? true : false);
        }
        return ret;
    }
};
