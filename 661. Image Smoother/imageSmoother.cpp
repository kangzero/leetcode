class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return {};
        
        int row = M.size();
        int col = M[0].size();
        
        vector<vector<int>> ret(row, vector<int>(col));
        vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = M[i][j];
                int size = 1;
                for (auto d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if ((x < 0) || (x >= row) || (y < 0) || (y >= col)) continue;
                    cnt += M[x][y]; 
                    size++;
                }
                ret[i][j] = cnt / size;
            }
        }
        
        return ret;
    }
};
