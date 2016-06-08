bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        // search the existence of the first letter
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (neighbor(board, word, i, j, 1, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool neighbor(vector<vector<char>>& board, string word, 
                    int i, int j, int pos, vector<vector<bool>>& v) {

        if (pos == word.size()) return true;
        
        // search four neighbors
        if (i > 0 && !v[i-1][j] && board[i-1][j] == word[pos]) {
            v[i-1][j] = true;
            if (neighbor(board, word, i-1, j, pos+1, v)) return true;
            v[i-1][j] = false;
        }
        
        if (i+1 < board.size() && !v[i+1][j] && board[i+1][j] == word[pos]) {
            v[i+1][j] = true;
            if (neighbor(board, word, i+1, j, pos+1, v)) return true;
            v[i+1][j] = false;
        }
        
        if (j > 0 && !v[i][j-1] && board[i][j-1] == word[pos]) {
            v[i][j-1] = true;
            if (neighbor(board, word, i, j-1, pos+1, v)) return true;
            v[i][j-1] = false;
        }
        
        if (j+1 < board[0].size() && !v[i][j+1] && board[i][j+1] == word[pos]) {
            v[i][j+1] = true;
            if (neighbor(board, word, i, j+1, pos+1, v)) return true;
            v[i][j+1] = false;
        }
        
        return false;
    }