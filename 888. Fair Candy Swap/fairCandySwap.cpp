#define HASH_SET    0
#define CONCISE     1

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
#if HASH_SET
        int sum_a = 0;
        int sum_b = 0;
        unordered_set<int> hash_a;
        unordered_set<int> hash_b;
        for (int i = 0; i < A.size(); i++) {
            sum_a += A[i];
            hash_a.insert(A[i]);
        }
        for (int i = 0; i < B.size(); i++) {
            hash_b.insert(B[i]);
            sum_b += B[i];
        }
        
        vector<int> ret(2);
        int delta = (sum_a - sum_b) / 2;
        if (delta > 0) {
            for (int i = 0; i < B.size(); i++) {
                if (hash_a.find(B[i] + delta) != hash_a.end()) {
                    ret[0] = B[i] + delta;
                    ret[1] = B[i];
                    return ret;
                }
            }
        } else {
            delta *= -1;
            for (int i = 0; i < A.size(); i++) {
                if (hash_b.find(A[i] + delta) != hash_b.end()) {
                    ret[0] = A[i];
                    ret[1] = A[i] + delta;
                    return ret;
                }
            }
        }
        
        return ret;
#elif CONCISE
        unordered_set<int> hash_b(B.begin(), B.end());
        
        int sum_a = 0;
        int sum_b = 0;
        for (int i = 0; i < A.size(); i++) sum_a += A[i];
        for (int i = 0; i < B.size(); i++) sum_b += B[i];
        
        int delta = (sum_b - sum_a) / 2;
        vector<int> ret(2);
        for (auto a: A) {
            if (hash_b.find(a + delta) != hash_b.end()) {
                ret = {a, a + delta};
                return ret;
            }
        }
        
        return ret;
#endif
    }
};
