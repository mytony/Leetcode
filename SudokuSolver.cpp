class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fillNum(board, 0);
    }
    
    // pos is from 0 to 80
    bool fillNum(vector<vector<char>>& board, int pos) {
        if (pos == 81) return true;
        
        if (board[pos / 9][pos % 9] != '.') {
            return fillNum(board, pos+1);
        }
        
        for (int i = 1; i < 10; i++) {
            if (validNum(board, pos, i)) {
                board[pos / 9][pos % 9] = '0' + i;
                if (fillNum(board, pos+1))
                    return true;
                else
                    board[pos / 9][pos % 9] = '.';
            }
        }
        return false;
    }
    
    // Given a number, check if filling it contradicts three rules
    bool validNum(vector<vector<char>>& board, int pos, int num) {
        int x = pos / 9, y = pos % 9; // index of pos
        
        // check square
        int sx = (x / 3) * 3; // x of top left point of the square
        int sy = (y / 3) * 3; // y of ...
        for (int i = sx; i < sx + 3; i++) {
            for (int j = sy; j < sy + 3; j++) {
                if (board[i][j] == '0' + num) {
                    return false;
                }
            }
        }
        
        // check horizontal
        for (int j = 0; j < 9; j++) {
            if (board[x][j] == '0' + num) {
                return false;
            }
        }
        
        // check vertical
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == '0' + num) {
                return false;
            }
        }
        return true;
    }
};