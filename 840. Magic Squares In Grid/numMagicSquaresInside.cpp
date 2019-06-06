class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < (r-2); i++) {
            for (int j = 0; j < (c-2); j++) {
                if (5 == (grid[i+1][j+1]) && (isValid(grid, i, j))) cnt++; 
            }
        }
        
        return cnt;
    }
                    
    bool isValid(vector<vector<int>>& grid, int a, int b) {
        vector<int> cnt(10);
        
        for (int i = a; i < a+2; i++) {
            for (int j = b; j < b+2; j++) {
                int k = grid[i][j];
                if ((k < 1) || (k > 9) || (cnt[k] == 1)) return false;
                cnt[k] = 1;
            }
        }
        
        if (15 != (grid[a][b] + grid[a][b+1] + grid[a][b+2])) return false; //row 0
        if (15 != (grid[a+1][b] + grid[a+1][b+1] + grid[a+1][b+2])) return false; //row 1
        if (15 != (grid[a+2][b] + grid[a+2][b+1] + grid[a+2][b+2])) return false; //row 2
        if (15 != (grid[a][b] + grid[a+1][b] + grid[a+2][b])) return false; //col 0
        if (15 != (grid[a][b+1] + grid[a+1][b+1] + grid[a+2][b+1])) return false; //col 1
        if (15 != (grid[a][b+2] + grid[a+1][b+2] + grid[a+2][b+2])) return false; //col 2
        if (15 != (grid[a][b] + grid[a+1][b+1] + grid[a+2][b+2])) return false; //diag 0
        if (15 != (grid[a+2][b] + grid[a+1][b+1] + grid[a][b+2])) return false; //diag 1
        
        return true;
    }
};
