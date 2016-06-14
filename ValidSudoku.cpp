class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool arr[9] = {false};
        
        // check square
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!checkSquare(board, 3*i, 3*j)) return false;
            }
        }
        
        // check horizontal
        for (int i = 0; i < 9; i++) {
            
            // reset array
            for (int j = 0; j < 9; j++) {
                arr[j] = false;
            }
            
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (arr[c-'0'-1]) return false;
                arr[c-'0'-1] = true;
            }
        }
        
        // check vertical
        for (int i = 0; i < 9; i++) {
            
            // reset array
            for (int j = 0; j < 9; j++) {
                arr[j] = false;
            }
            
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                if (arr[c-'0'-1]) return false;
                arr[c-'0'-1] = true;
            }
        }
        return true;
    }
    
    // (x,y) is top left point of a 3*3 square
    bool checkSquare(vector<vector<char>>& board, int x, int y) {
        bool arr[9] = {false};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[x+i][y+j];
                if (c == '.') continue;
                if (arr[c-'0'-1]) return false;
                arr[c-'0'-1] = true;
            }
        }
        return true;
    }
};