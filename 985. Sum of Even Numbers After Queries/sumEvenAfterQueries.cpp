class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ret;
        
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            if ((A[i] & 1) == 0) sum += A[i]; 
        }
        
        for (int i = 0; i < queries.size(); i++) {
            if ((A[queries[i][1]] & 1) == 0) {
                sum -= A[queries[i][1]];
            }
            A[queries[i][1]] += queries[i][0];
            if ((A[queries[i][1]] & 1) == 0) {
                sum += A[queries[i][1]];
            }
            ret.push_back(sum);
        }
        
        return ret;
    }
};
