class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int r = 0; r < (matrix.size() - 1); r++) {
            for (int c = 0; c < (matrix[0].size() - 1); c++) {
                if (matrix[r][c] != matrix[r+1][c+1]) return false;
            }
        }
        return true;
    }
};
