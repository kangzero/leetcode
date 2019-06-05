#define TWO_POINTER 0
#define MAX_VALUE 1

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
#if TOW_POINTER
        if (A.size() < 3) return false;
        
        int l = 0;
        int r = A.size() - 1;
        //cout << l << " " << r << endl;
        
        while (((l+1) < r) && (A[l] < A[l+1])) l++;
        //cout << l << endl;
        
        while (((r-1) > 0) && (A[r-1] > A[r])) r--;
        //cout << r << endl;
        
        return (l == r);
#elif MAX_VALUE
        if (A.size() < 3) return false;
        
        int index = 0;
        
        for (int i = 0; i < A.size()-1; i++) {
            if (A[i] < A[i+1]) {
                continue;
            } else {
                index = i;
                break;
            }
        }
        
        if ((index == (A.size()-1)) || (index == 0)) return false;
        
        for (int i = index; i < (A.size()-1); i++) {
            if (A[i] <= A[i+1]) return false;
        }
        
        return true;
#endif
    }
};
