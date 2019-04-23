#define REPLACE_A 0
#define NEW_MATRIX 1

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
#if REPLACE_A
        int r = A.size();
        int c = A[0].size();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < (c+1)/2; j++) {
                int tmp = A[i][j] ^ 1;
                A[i][j] = A[i][c-1-j] ^ 1;
                A[i][c-1-j] = tmp;
            }
        }
        
        return A;
#elif NEW_MATRIX
        vector<vector<int>> ret(A.size());
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = A[0].size()-1; j >= 0; j--) {
                ret[i].push_back(A[i][j] ^ 1);
            }
        }
        
        return ret;
#endif
    }
};
