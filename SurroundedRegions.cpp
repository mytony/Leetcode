class Solution {
public:
    // Result: TLE
    // Search 'O' from top-left to bottom-right
    // For each 'O', do BFS. Set a flag if there is a 'O' on the boarder
    // For each BFS, flip all elements on the path if the flag is not set
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        
        // initialize the visited board with X and O on the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = board[i][j] == 'X' ? 1 : 0;
            }
        }
        
        bool onEdge = false;
        queue<int> bfs_q; // store 1-D coordinate of (i,j)
        
        // for every unvisited O, run BFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    continue;
                }
                
                onEdge = false; // reset for each region
                vector<int> path; // record the path if we want to flip captured Os
                bfs_q.push(i * n + j);
                
                while( !bfs_q.empty() ) {
                    int k = bfs_q.front();
                    int x = k / n;
                    int y = k % n;
                    bfs_q.pop();
                    visited[x][y] = 1;
                    path.push_back(k);
                    
                    // The region will not be captured in the end
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                        onEdge = true;
                    }
                    
                    // visit four possible O neighbors
                    for (int a = -1; a < 2; a += 2) {
                        // x is changed
                        if (x+a >= 0 && x+a < m) {
                            if (visited[x+a][y] == 0) {
                                bfs_q.push((x + a) * n + y);
                            }
                        }
                        // y is changed
                        if (y+a >= 0 && y+a < n) {
                            if (visited[x][y+a] == 0) {
                                bfs_q.push(x * n + y + a);
                            }
                        }
                    }
                }
                // flip the region if it is captured
                if (!onEdge) {
                    for (int k : path) {
                        int x = k / n;
                        int y = k % n;
                        board[x][y] = 'X';
                    }
                }
            }
        }
    }
};