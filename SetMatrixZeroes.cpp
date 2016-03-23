class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row, col, fr, fc; // could only use fr or fc in discuss forum
        fr = fc = 1;
        row = matrix.size();
        if (row == 0) {
            return;
        }
        col = matrix[0].size();
        
        // go through entire matrix and store state
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]) {
                    continue;
                }
                if (i == 0) {
                    fr = 0;
                    continue;
                }
                if (j == 0) {
                    fc = 0;
                    continue;
                }
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        // go through entire matrix and assign zero depeding on stored states
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
                if ((i == 0 && fr == 0) || (j == 0 && fc == 0)) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};