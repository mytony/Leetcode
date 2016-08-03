class Solution {
public:
    // Forum solution
    // But still not good, see below comment
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        
        // change all 'O' to '1' if they are on the boarder or connected to
        for (int i = 0; i < m; i++) {
            alter(board, i, 0); // left boarder
            if (n > 1) {
                alter(board, i, n-1); // right boarder
            }
        }
        for (int i = 1; i+1 < n; i++) {
            alter(board, 0, i); // top boarder
            if (m > 1) {
                alter(board, m-1, i); // bottom boarder
            }
        }
        
        // change all 'O' to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // change all '1' to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void alter(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        
        if (board[x][y] != 'O') {
            return;
        }
        board[x][y] = '1';
        // check neighbors
        ///////////////////////////////////////
        // In this thread: https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms/14
        // They discussed that actually this DFS solution is problematic, should use BFS instead
        // It passes if you write x > 1 to break the chain in below case, but x >= 1 will stack overflow
        
        // OOOOOOOOOO
        // XXXXXXXXXO
        // OOOOOOOOOO
        // OXXXXXXXXX
        // OOOOOOOOOO
        // XXXXXXXXXO
        // OOOOOOOOOO
        // OXXXXXXXXX
        // OOOOOOOOOO
        // XXXXXXXXXO
        
        // but x > 1 will fail too if leetcode have a case like below:
        
        // OOOOOOOOOOOX
        // XXXXXXXXXXOX
        // XOOOOOOOOOOX
        // XOXXXXXXXXXX
        // XOOOOOOOOOOX
        // XXXXXXXXXXOX
        // XOOOOOOOOOOX
        // XOXXXXXXXXXX
        // XOOOOOOOOOOX
        // XXXXXXXXXXOX
        ///////////////////////////////////////
        if (x > 1) {
            alter(board, x-1, y);
        }
        if (y > 1) {
            alter(board, x, y-1);
        }
        if (x + 1 < m) {
            alter(board, x+1, y);
        }
        if (y + 1 < n) {
            alter(board, x, y+1);
        }
    }
};