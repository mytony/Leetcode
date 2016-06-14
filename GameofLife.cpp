// If thinking of a not in-place solution, then basic one is
// create another 2d array to store next state. Go through
// every cell and decide its next state based on neighbors

// In-place: use a bit other than LSB to store next state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // use last second bit to record next state
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (isLive(board, i, j))    board[i][j] |= 0x2;
            }
        }
        
        // move every cell to right by 1 bit
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
    
    bool isLive(vector<vector<int>>& board, int r, int c) {
        bool status = board[r][c] & 1;
        int live_count = 0;
        for (int i = r-1; i < r+2; i++) {
            for (int j = c-1; j < c+2; j++) {
                // out of boarder
                if (i < 0 || j < 0 || 
                    i == board.size() ||
                    j == board[0].size() || 
                    (i == r && j == c)) {
                    continue;   
                }
                if (board[i][j] & 1)    live_count++;
            }
        }
        
        if (status && (live_count < 2 || live_count > 3))
            return false;
        else if (!status && live_count != 3)
            return false;
        else
            return true;
    }
};