
#define SOL_1 0
#define SOL_2 1

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
#if SOL_1
        vector<vector<int>> ret;
        
        int len = S.size();
        int i = 0, j = 0;
        while (i < len) {
            while ((j < len) && (S[i] == S[j])) j++;
            if  ((j - i) >= 3) ret.push_back({i, j-1});
            i = j;
        }
        
        return ret;
#elif SOL_2
        vector<vector<int>> ret;
        
        int len = S.size();
        int start = 0;
        for (int i = 1; i < len; i++) {
            if ((i < len) && (S[i] == S[start])) continue;
            if ((i - start) >= 3) ret.push_back({start, i-1});
            start = i;
        }
        
        return ret;
#endif
    }
};
