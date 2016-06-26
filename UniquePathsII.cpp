class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // the value is the number of ways to get there
        vector<vector<int>> grid (m, vector<int>(n, 0));
        
        // First row and column are only reachable by one way
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) break;
            grid[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) break;
            grid[0][i] = 1;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) continue;
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
            }
        }
        
        return grid[m-1][n-1];
    }
};