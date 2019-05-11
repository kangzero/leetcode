#define TWO_PASS 0 
#define ONE_PASS 1

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
#if TWO_PASS
        int n = A.size();
        vector<int> ret(n, 0);
    
        int k = 0;
        for(int i = 0; i < A.size(); i++) {
            if ((A[i] % 2) == 0) {
                ret[k] = A[i];
                k += 2;
            }
        }
        
        k = 1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 != 0) {
                ret[k] = A[i];
                k += 2;
            }
        }
        
        return ret;
#elif ONE_PASS
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if ((A[i] % 2) != 0) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        
        return A;
#endif
    }
};
