#define NATIVE_SOL 0
#define CONCISE_SOL 1

class Solution {
public:
#if NATIVE_SOL
    int numRookCaptures(vector<vector<char>>& board) {
        int ret = 0;
        
        int px = 0, py = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    px = i;
                    py = j;
                    break;
                }
            }
        }
        
        for (int l = (py - 1); l >= 0; l--) {
            if (board[px][l] == 'p') {
                ret++;
                break;
            }
            if (board[px][l] != '.') break;
        }
        
        for (int r = (py + 1); r < 8; r++) {
            if (board[px][r] == 'p') {
                ret++;
                break;
            }
            if (board[px][r] != '.') break;
        }
        
         for (int u = (px - 1); u >= 0; u--) {
            if (board[u][py] == 'p') {
                ret++;
                break;
            }
            if (board[u][py] != '.') break;
        }
        
        for (int d = (px + 1); d < 8; d++) {
            if (board[d][py] == 'p') {
                ret++;
                break;
            }
            if (board[d][py] != '.') break;
        }
        
        return ret;
    }
#elif CONCISE_SOL
    int numRookCaptures(vector<vector<char>>& board) {
        int ret = 0;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    return cap(board, i, j, 0, -1) + cap(board, i, j, 0, 1) + cap(board, i, j, -1, 0) + cap(board, i, j, 1, 0); 
                }
            }
        }
        
        return 0;
    }
    
    int cap(vector<vector<char>>& board, int x, int y, int dx, int dy) {
        while ((x >= 0) && (x < board.size()) && (y >= 0) && (y < board[x].size()) && (board[x][y] != 'B')) {
            if (board[x][y] == 'p') return 1;
            x += dx;
            y += dy;
        }
        return 0;
    }
#endif
};
