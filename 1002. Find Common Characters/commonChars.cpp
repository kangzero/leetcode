class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> list;
        int checklist[100][26] = {0};
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                checklist[i][A[i][j] - 'a']++; 
            }
        }
        
        int cnt = 0;
        for (int n = 0; n < 26; n++) {
            int min = INT_MAX;
            for (int m = 0; m < A.size(); m++) {
                min = (min < checklist[m][n]) ? min : checklist[m][n];
                if (min == 0) break;
            }
            while (min > 0) {
                list.push_back(string(1, n + 'a'));
                min--;
                cnt++;
            }
        } 
        
        return list;
    }
};
