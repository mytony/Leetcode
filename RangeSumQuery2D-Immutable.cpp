class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        sum.assign(m, vector<int>(n, 0));
        
        // First we compute value as the sum from first column to its column in the row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    sum[i][j] = matrix[i][j];
                } else {
                    sum[i][j] = sum[i][j-1] + matrix[i][j];
                }
            }
        }
        // Then accumulate the value for each value in column
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] += sum[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Big area - small - small + overlapping small
        int area = sum[row2][col2];
        if (row1 != 0) {
            area -= sum[row1-1][col2];
        }
        if (col1 != 0) {
            area -= sum[row2][col1-1];
        }
        if (row1 != 0 && col1 != 0) {
            area += sum[row1-1][col1-1];
        }
        return area;
    }
private:
    // element (i,j) means the sum of elements inside rectangles (0,0) to (i,j)
    vector<vector<int>> sum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);