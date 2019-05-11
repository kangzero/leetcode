int numRookCaptures(char** board, int boardRowSize, int *boardColSizes) {
    int cnt = 0;
    
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < (*boardColSizes); j++) {
            if (board[i][j] == 'R') {
                for (int r = (j+1); r < (*boardColSizes); r++) {
                    if (board[i][r] == 'p') {
                        cnt++;
                        break;
                    }
                    if (board[i][r] != '.') {
                        break;
                    }
                }
                for (int d = (i+1); d < boardRowSize; d++) {
                    if (board[d][j] == 'p') {
                        cnt++;
                        break;
                    }
                    if (board[d][j] != '.') {
                        break;
                    }
                }
                for (int l = (j-1); l >= 0; l--) {
                    if (board[i][l] == 'p') {
                        cnt++;
                        break;
                    }
                    if (board[i][l] != '.') {
                        break;
                    }
                }
                for (int u = (i-1); u >= 0; u--) {
                    if (board[u][j] == 'p') {
                        cnt++;
                        break;
                    }
                    if (board[u][j] != '.') {
                        break;
                    }
                }
                return cnt;
            }
      
        }
    }
    
    return 0;
}
